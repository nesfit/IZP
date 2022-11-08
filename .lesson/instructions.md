# 07-02: Práce s ukazateli na struktury
V tomto příkladě si vyzkoušíte jak pracovat s ukazateli na struktury ve funkcích.


### dereferenční operátor `*`, `->`
Operátor `->` jako operátor odpovídá dereferenci nad strukturou, respektive ukazatelem na strukturu.
```c
typedef struct {
    int year;
    int month;
    int day;
} Date;
```
```c
Date date = {.year=2022, .month=10, .day=30};
Date *datePtr = &date;

printf("year: %d\n", date.year); // 2022
printf("year: %d\n", datePtr->year); // 2022
printf("year: %d\n", (*datePtr).year); // 2022
```


## Soubory příkladu

| Soubor                                  | Popis obsahu                                                |
| --------------------------------------- | ----------------------------------------------------------- |
| [`main.c`](/main.c)                       | Vaše implementace úkolů
| [`types.h`](/types.h)                     | Datové struktury a hlavičky funkcí, které máte k dispozici
| [`test.h`](/test.h) a [`test.c`](/test.c)   | Logika pro automatizované testy
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

1. implementujte funkci `parse_args(char **, int, Config *)`
    - funkce zpracovává CLI argumenty předané programu při spuštění
    - popis přijímaných argumentů programu:

```
syntax: ./main [-x|-y] [-n COUNT] -s STR
    -x and -y are optional and mutually exclusive
    -s STR - mandatory, STR is a string
    -n COUNT - optional, COUNT is non-negative integer (default: 10)
```
