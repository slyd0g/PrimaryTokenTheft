# PrimaryTokenTheft
Main code taken from [@kondecuotas](https://twitter.com/kondencuotas) [blog](https://ired.team/).

Steal a primary token and spawn cmd.exe using the stolen token.

- Added the ability to pass a PID by command-line argument.
- Automatically enable SeDebugPrivilege
- Reduced privileges needed for OpenProcess(), OpenProcessToken() and DuplicateTokenEx() from TOKEN_ALL_ACCESS/PROCESS_ALL_ACCESS to the bare minimum needed for each API call.


# Elevating to SYSTEM 
![GetSystem](https://raw.githubusercontent.com/justinbui/PrimaryTokenTheft/master/example.png)

# Credit 
Main blog and source code: https://ired.team/offensive-security/privilege-escalation/t1134-access-token-manipulation

Elevating to system with Winlogon: https://twitter.com/monoxgas/status/1109892490566336512?s=20

Figured out minimum privileges to call DuplicateTokenEx() with for CreateProcessWithTokenW to work here: https://stackoverflow.com/questions/5447418/why-is-createprocesswithtokenw-failing-with-error-access-denied (MSDN docs are wrong)

MSDN Enabling Privileges: https://docs.microsoft.com/en-us/windows/win32/secauthz/enabling-and-disabling-privileges-in-c--
