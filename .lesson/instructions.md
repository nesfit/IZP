# 07-01: Práce s ukazateli na pole
V tomto příkladě si vyzkoušíte jak pracovat s "různými typy" ukazatelů na pole ve funkcích.

Jednotlivé úkoly najdete přímo v kódu.

---

## Teorie
Užitečné ukázky kódu relevantní pro práci na tomto cvičení.

### automatická alokace na zásobníku (stack)
```c
int stackInts[5] = {1, 2, 3, 4, 5};
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

---

## `Makefile` recepty

Recepty spustitelné z příkazové řádky prostřednictvím příkazu `make $RECIPE`.

| Název receptu | Popis obsahu                                          |
| ------------- | ----------------------------------------------------- |
|               | Kompilace vašeho programu
| `test`        | Spuštění testovacích scriptů pro aktuální zadání
| `submit`      | Spuštění testovacích scriptů pro aktuální zadání s odevzdáním řešení
| `clean`       | Odstranění překladem-generovaných souborů


## Soubory příkladu

| Soubor                                    | Popis obsahu                                                |
| ----------------------------------------- | ----------------------------------------------------------- |
| [`main.c`](/main.c)                       | Vaše implementace úkolů
| [`types.h`](/types.h)                     | Datové struktury a hlavičky funkcí, které máte k dispozici
| [`test.h`](/test.h) a [`test.c`](/test.c) | Logika pro automatizované testy
| [`student-config.sh`](/student-config.sh) | Konfigurace testovacích scriptů vašeho repozitáře
