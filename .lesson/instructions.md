# 07-02: Práce s ukazateli na pole
V tomto příkladě si vyzkoušíte jak pracovat s "různými typy" ukazatelů na pole ve funkcích.


## Termíny a názvosloví

### automatická alokace na zásobníku (stack)
```c
int stackInts[5] = {1, 2, 3, 4, 5};
```

### alokace na hromadě (heap)
```c
int *heapInts = malloc(5 * sizeof(int));
```
```c
// dynamicky alokovaná paměť musí být programátorem opět VŽDY uvolněna
free(heapInts);
```

### inicializace pole
```c
// inicializace samých nul
for (int i = 0; i < 5 * sizeof(*heapInts); i++)
{
    heapInts[i] = 0;
}
```

```c
// inicializace samých nul
memset(heapInts, 0, 5 * sizeof(*heapInts));
```


### předávání pole podprogramům
```c
int rel_isFunction(Pair rel[5], ...);
int rel_isEquivalence(Pair *rel, ...);
```

```c
pair_t rel[5] = {...};
rel_isFunction(rel, ...);
rel_isEquivalence(rel, ...);
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

1. implementujte funkci `parse_args(char **, int)`
    - funkce zpracovává CLI argumenty předané programu při spuštění
    - popis přijímaných argumentů programu:

```
syntax: ./main [-x|-y] [-n COUNT] -s STR
    -x and -y are optional and mutually exclusive
    -s STR - mandatory, STR is a string
    -n COUNT - optional, COUNT is non-negative integer (default: 10)
```
