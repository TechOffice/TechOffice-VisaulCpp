# Wifi

```
PWLAN_INTERFACE_INFO_LIST interfaceList = NULL;
DWORD clientVersion = 2;
DWORD wlanApiVersion = 0;
HANDLE clientHandle = NULL;
WlanOpenHandle(clientVersion, NULL, &wlanApiVersion, &clientHandle);
WlanEnumInterfaces(clientHandle, NULL, &interfaceList);

std::cout << " Number of Interface: " << interfaceList->dwNumberOfItems << std::endl ;

for (int i = 0; i < (int)interfaceList->dwNumberOfItems; i++) {
	PWLAN_INTERFACE_INFO interfaceInfo = (WLAN_INTERFACE_INFO *)&interfaceList->InterfaceInfo[i];
	
	// Get List
	PWLAN_AVAILABLE_NETWORK_LIST availaleNetworkList = NULL;
	WlanGetAvailableNetworkList(clientHandle, &interfaceInfo->InterfaceGuid, 0, NULL, &availaleNetworkList);
	std::cout << " Number of Available Network: " << availaleNetworkList->dwNumberOfItems << std::endl;

	for (int j = 0; j < (int)availaleNetworkList->dwNumberOfItems; j++) {
		PWLAN_AVAILABLE_NETWORK networkEntry = (WLAN_AVAILABLE_NETWORK *)& availaleNetworkList->Network[j];
		std::cout << networkEntry->dot11Ssid.ucSSID << std::endl;
	}
}

std::cin.get();
return 0;
```

## Reference
* https://docs.microsoft.com/en-us/windows/desktop/NativeWiFi/portal