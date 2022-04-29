Welcome to my first External Memory Editor

This code is simple, we use the windows api to access a process, grant change access, and then we write in the process memory what we want.

ATENTION
Dont forget to set the project properties and enable Multi-Byte Character Set.

Project property > configuration properties > advanced properties > Character SET

Links with information and examples used in the code:

(CreateToolhelp32Snapshot function (tlhelp32.h))
https://docs.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot

(WriteProcessMemory function (memoryapi.h))
https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-writeprocessmemory

(Taking a Snapshot and Viewing Processes)
https://docs.microsoft.com/en-us/windows/win32/toolhelp/taking-a-snapshot-and-viewing-processes
