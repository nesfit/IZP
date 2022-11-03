# 06-03: Relace jako funkce
V tomto příkladě aplikujete znalosti ukazatelů, struktur a funkcí z předcházejících cvičení.
Dále si také vyzkoušíte dynamickou alokaci paměti.


## Termíny a názvosloví

### automatická alokace na zásobníku (stack)
```c
int stackInts[5] = {1, 2, 3, 4, 5};
```

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
memset(heapInts, 0, 5 * sizeof(*heapInts));
```

```c
// inicializace samých nul
for (int i = 0; i < 5 * sizeof(*heapInts); i++)
{
    heapInts[i] = 0;
}
```

### předávání pole podprogramům
```c
int rel_isFunction(Pair rel[5], set_t set, ...);
```

```c
pair_t rel[5] = {...};
rel_isFunction(rel, ...);
```


## Popis příkladu

| Soubor                                    | Popis obsahu |
| ----------------------------------------- | ------------ |
| [`main.c`](/main.c)                       | Vaše implementace úkolů
| [`types.h`](/types.h)                     | Datové struktury a hlavičky funkcí, které máte k dispozici
| [`test.h`](/test.h) a [`test.c`](/test.c) | Logika pro automatizované testy
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

1. seznamte se s definovanými datovými typy (`Pair`, `Set`) v souboru [types.c](/types.c)
3. deklarujte a staticky inicializujte pole instancí těchto struktur v souboru [main.c](/main.c)
   - nechť toto pole reprezentuje relaci nad množinou celých čísel
4. implementujte funkci `int rel_isFunction(Pair[], int, Set)`
    - funkce provede kontrolu relace a rozhodne, zda je relace funkcí či ne
        - všechny vzory z definitičního oboru mají právě jeden obraz v oboru hodnot
    - metoda přijímá 3 parametry:
        - definici relace (pole dvojic čísel),
        - velikost relace (délku pole),
        - definici číselného oboru,
    - metoda vrací hodnotu `1` pokud relace je funkcí, `0` jinak
5. implementujte funkci `void rel_minMax(Pair[], int, int*, int*)`
6. implementujte funkci `int rel_isEquivalence(Pair[], int, Set)`
    - metoda vrací hodnotu `1` pokud relace je relací ekvivalence, `0` jinak
