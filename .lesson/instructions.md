# 06-01: Úvod k ukazatelům

Ukázky kódů níže vycházejí z následujícího kódu:
```c
int intA = 10;
int intB = 2;
float floatA = 10.0;
float floatB = 2.0;
char character = 'X';
```

## Termíny a názvosloví

### Datový typ ukazatel
Znak `*` v datovém typu signifikuje ukazatel "na nějaký" datový typ.
Počet odpovídá hloubce zanoření.
```c
int *numberPtr;
float *floatPtr;
char *charPtr; // pozor, nejedná se o řetězec
```

### referenční operátor `&`
Operátor `&` vytváří adresu na poskytnutý operand.
```c
intPtr = &intA;
floatPtr = &floatA;
charPtr = &character;
```

### dereferenční operátor `*`
Operátor `*` jako operátor odpovídá jak násobení tak dereferenci.
Jeho význam učtuje kontext!
```c
// čtení hodnoty z adresy
intA = *numberPtr;
floatA = *floatPtr;
character = *charPtr;
```

```c
// zápis hodnoty na adresu
*numberPtr = 42;
*floatPtr = 42.42;
*charPtr = 'Y';
```

### tisk hodnoty ukazatele
Obsahem datového typu ukazatele je vždy adresa.
V `printf` je pro tisk adresy k dispozici formát `%p`:
```c
printf("Adresa: %p == %p", intPtr, &intA);
printf("Referencovaná hodnota: %d == %d", *intPtr, intA);
```

### předávání parametrů odkazem
Funkce vyžadující odkazy budou mít ve svých hlavičkách uvedeny odpovídající datové typy.
```c
void swapInts(int *a, int *b);
```

Jejich volání pak probíhá (za pomoci operátoru reference) následovně: 
```c
swapInts(&intA, &intB);
```

## Přehled souborů příkladu 

| Soubor                                    | Popis obsahu                                                |
| ----------------------------------------- | ----------------------------------------------------------- |
| [`main.c`](/main.c)                       | Vaše implementace úkolů
| [`student-config.sh`](/student-config.sh) | Konfigurace testovacích scriptů vašeho repozitáře


## `Makefile` recepty

Recepty spustitelné z příkazové řádky prostřednictvím příkazu `make $RECIPE`.

| Název receptu | Popis obsahu                                                |
| ------------- | ----------------------------------------------------------- |
| `main`        | Kompilace vašeho programu
| `main-debug`  | Kompilace vašeho programu za účelem ladění
| `test`        | Spuštění testovacích scriptů pro aktuální zadání
| `submit`      | Spuštění testovacích scriptů pro aktuální zadání s odevzdáním řešení
| `clean`       | Odstranění překladem-generovaných souborů


## Úkoly

1. implementujte metodu `void swapInts(int *, int *)`
    - metoda vymění hodnoty dvou celočíselných proměnných
    - metoda přijímá ukazatele na 2 celočíselné proměnné
    - _metoda má návratový datový typ `void`, tzn. nic nevrací_
