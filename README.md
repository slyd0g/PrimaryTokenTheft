# PrimaryTokenTheft
Steal a primary token and spawn cmd.exe using the stolen token.

Main code taken from @kondecuotas blog. Added the ability to pass a PID by command-line argument and dug into the minimum privileges needed for OpenProcess(), OpenProcessToken() and DuplicateTokenEx()

# Credit 
Primary code from @kondencuotas here: https://ired.team/offensive-security/privilege-escalation/t1134-access-token-manipulation

Figured out minimum privileges to call DuplicateTokenEx() with for CreateProcessWithTokenW to work here: https://stackoverflow.com/questions/5447418/why-is-createprocesswithtokenw-failing-with-error-access-denied (MSDN docs are wrong)
