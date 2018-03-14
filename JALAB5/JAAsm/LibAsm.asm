.model flat, stdcall
.data
DataString DB 'AGIJKSZ', 0FFH ; definicja ciagu znakow
.code
;****************************************************************************
;* Procedura FindChar_1 wyszukiwania znaku 'J' w ciagu 'DataString' *
;* *
;* Bezposrednia adresacja indeksowa *
;* Parametry wejsciowe: *
;* AH - szukany znak 'J' *
;* Parametry wyjsciowe: *
;* EAX - BOOL TRUE Found, FALSE not found *
;* *
;****************************************************************************
FindChar_1 PROC
MOV ESI, OFFSET DataString ; zaladuj offset zmiennej 'DataString' do rej. SI
MOV AH, 'J' ; zaladuj kod litery 'J' do rej. AH
Check_End:
CMP BYTE PTR [ESI], 0FFH ; czy koniec lancucha (znak specjalny FF)?
JE Not_Find ; znaleziono znak konca (wartownik)
CMP AH, [ESI] ; porownaj znak z elementem lancucha 'DataString'
JE Got_Equal ; znaleziono znak!
ADD ESI, 1 ; inkrementuj offset Instytut Informatyki Politechniki Œl¹skiej Zespó³ Mikroinformatyki i Teorii Automatów Cyfrowych Rok akademicki: Rodzaj studiów*: SSI/NSI/NSM Jêzyki Asemblerowe LAB II
JMP Check_End ; petla wyszukiwania
Got_Equal:
MOV DL, [ESI] ; zaladuj znaleziony znak do DL
JMP Done
Not_Find:
MOV EAX,0 ; nie znaleziono znaku
RET ; powrot z procedury
Done:
MOV EAX,1 ; znaleziono znak
RET ; powrot z procedury
FindChar_1 ENDP ; koniec FindChar_1
;****************************************************************************
;* Procedura FindChar_2 wyszukiwania znaku 'J' w ciagu 'LocalString' *
;* *
;* Bezposrednia adresacja indeksowa *
;* Parametry wejsciowe: *
;* AH - szukany znak 'J' *
;* Parametry wyjsciowe: *
;* EAX - BOOL TRUE Found, FALSE not found *
;* *
;****************************************************************************
FindChar_2 PROC
LocalString DB 0C3H,'AGIJKSZ', 0FFH ; definicja ciagu znakow
MOV ESI, OFFSET LocalString ; zaladuj offset zmiennej 'LocalString' do rej. ESI
MOV AH, 'J' ; zaladuj kod litery 'J' do rej. AH
Check_End:
CMP BYTE PTR [ESI], 0FFH ; czy koniec lancucha (znak specjalny FF)?
JE Not_Find ; znaleziono znak konca (wartownik)
CMP AH, [ESI] ; porownaj znak z elementem lancucha 'LocalString'
JE Got_Equal ; znaleziono znak!
ADD ESI, 1 ; inkrementuj offset
JMP Check_End ; petla wyszukiwania
Got_Equal:
MOV DL, [ESI] ; zaladuj znaleziony znak do DL
JMP Done
Not_Find:
MOV EAX,0 ; nie znaleziono znaku
RET ; powrot z procedury
Done:
MOV EAX,1 ; znaleziono znak
RET ; powrot z procedury
FindChar_2 ENDP ; koniec FindChar_2
FindChar_3 PROC AppString: DWORD
;****************************************************************************
;* Procedura FindChar_3 wyszukiwania znaku 'J' w ciagu 'AppString' *
;* *
;* Bezposrednia adresacja indeksowa *
;* Parametry wejsciowe: *
;* AH - szukany znak 'J' *
;* Rej: ESI - offset adresu zmiennej 'AppString' *
;* Parametry wyjsciowe: *
;* EAX - BOOL TRUE Found, FALSE not found *
;* *
;****************************************************************************
MOV ESI, AppString ; zaladuj offset zmiennej 'AppString' do rej. ESI
MOV AH, 'J' ; zaladuj kod litery 'J' do rej. AH
Check_End:
CMP BYTE PTR [ESI], 0FFH ; czy koniec lancucha (znak specjalny FF)?
JE Not_Find ; znaleziono znak konca (wartownik)
CMP AH, [ESI] ; porownaj znak z elementem lancucha 'AppString'
JE Got_Equal ; znaleziono znak!
ADD ESI, 1 ; inkrementuj offset
JMP Check_End ; petla wyszukiwania
Got_Equal:
MOV DL, [ESI] ; zaladuj znaleziony znak do DL
JMP Done
Not_Find:
MOV EAX,0 ; nie znaleziono znaku
RET ; powrot z procedury
Done:
MOV EAX,1 ; znaleziono znak
RET ; powrot z procedury
FindChar_3 ENDP ; koniec FindChar_3
;****************************************************************************
;* Procedura FindChar_4 wyszukiwania znaku 'J' w ciagu 'DataString' *
;* *
;* Bezposrednia adresacja indeksowa *
;* Parametry wejsciowe: *
;* Rej: ESI - indeks zmiennej 'DataString' *
;* AH - szukany znak 'J' *
;* Parametry wyjsciowe: *
;* EAX - BOOL TRUE Found, FALSE not found *
;* *
;****************************************************************************
FindChar_4 PROC NEAR ; deklaracja procedury FindChar_4
MOV ESI, 0 ; zaladuj indeks lancucha 'DataString' do ESI
MOV AH, 'J' ; zaladuj kod litery 'J' do rej. AH
DEC SI;
Check_End:
INC SI ; inkrementuj indeks
CMP DataString[ESI], 0FFH ; czy koniec lancucha (znak specjalny FF)?
JE Not_Find ; znaleziono znak konca (wartownik)
CMP AH, DataString[ESI] ; porownaj znak z elementem lancucha 'DataString'
JNE Check_End ; nie znaleziono znaku
;MOV DL, DataString[ESI] ; zaladuj znaleziony znak do DL
MOV EAX,1 ; znaleziono znak
RET ; powrot z procedury
Not_Find:
MOV EAX,0 ; nie znaleziono znaku
RET ; powrot z procedury

FindChar_4 ENDP ; koniec FindChar_4
;****************************************************************************
;* Procedura FindChar_5 wyszukiwania znaku 'J' w ciagu 'DataString' *
;* *
;* Adresacja Base + Index *
;* Parametry wejsciowe: *
;* Rej: BX - offset zmiennej 'DataString' *
;* Parametry wyjsciowe: *
;* EAX - BOOL TRUE Found, FALSE not found *
;* *
;****************************************************************************
FindChar_5 PROC NEAR
MOV EBX, OFFSET DataString ; zaladuj offset zmiennej 'DataString' do rej. EBX
CMP BYTE PTR [EBX+0], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
CMP BYTE PTR [EBX+1], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
CMP BYTE PTR [EBX+2], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
CMP BYTE PTR [EBX+3], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
CMP BYTE PTR [EBX+4], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
CMP BYTE PTR [EBX+5], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
CMP BYTE PTR [EBX+6], 'J' ; porownaj znak z elementem lancucha 'DataString'
JE Got_It ; znaleziono znak
Not_Find:
MOV EAX,0 ; zaladuj znak zapytania do DL
RET ; powrot z procedury
Got_It:
MOV EAX,1 ; wyswietl znak ne ekranie
RET ; powrot z procedury
FindChar_5 ENDP ; koniec FindChar_5
;****************************************************************************
;* Procedura FindChar_6 wyszukiwania znaku 'J' w ciagu 'DataString' *
;* *
;* adresacja Disp [EBX+ESI] *
;* Parametry wejsciowe: *
;* Rej: EBX - offset zmiennej 'DataString' *
;* ESI - przemieszczenie *
;* AH - szukany znak 'J' *
;* Parametry wyjsciowe: *
;* EAX - BOOL TRUE Found, FALSE not found *
;* *
;****************************************************************************
FindChar_6 PROC NEAR
MOV EBX, OFFSET DataString ; zaladuj offset zmiennej 'String' do rej. ESI
XOR ESI, ESI ; wyzeruj indeks lancucha 'String' w ESI
MOV AH, 'J' ; zaladuj kod litery 'J' do rej. AH
Check_End:
CMP BYTE PTR [EBX+ESI], 0FFH ; czy koniec lancucha (znak specjalny FF)?
JE Not_Find ; znaleziono znak konca (wartownik)
CMP AH, BYTE PTR [EBX+ESI] ; porownaj znak z elementem lancucha 'String'
JE Got_Equal ; znaleziono znak!
INC ESI ; inkrementuj indeks
JMP Check_End ; petla wyszukiwania
Got_Equal:
MOV DL, [EBX+ESI] ; zaladuj znaleziony znak do DL
JMP Done
Not_Find:
MOV EAX,0 ; nie znaleziono znaku
RET
Done:
MOV EAX,1 ; znaleziono znak
RET ; powrot z procedury
FindChar_6 ENDP ; koniec FindChar_6
;****************************************************************************
END