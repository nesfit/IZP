# 07-03: Funkce pro práci se vektory
V tomto cvičení si vyzkoušíte práci s dynamickou alokací paměti.

## `Makefile` recepty

Recepty spustitelné z příkazové řádky prostřednictvím příkazu `make $RECIPE`.

| Název receptu | Popis obsahu                                                |
| ------------- | ----------------------------------------------------------- |
| `main`        | Kompilace vašeho programu
| `main-debug`  | Kompilace vašeho programu za účelem ladění
| `test`        | Spuštění testovacích scriptů pro aktuální zadání
| `submit`      | Spuštění testovacích scriptů pro aktuální zadání s odevzdáním řešení
| `clean`       | Odstranění překladem-generovaných souborů


## Soubory příkladu

| Soubor                                  | Popis obsahu                                                |
| --------------------------------------- | ----------------------------------------------------------- |
| [`main.c`](/main.c)                       | Vaše implementace úkolů
| [`types.h`](/types.h)                     | Datové struktury a hlavičky funkcí, které máte k dispozici
| [`test.h`](/test.h) a [`test.c`](/test.c)   | Logika pro automatizované testy
| [`student-config.sh`](/student-config.sh) | Konfigurace testovacích scriptů vašeho repozitáře


## Úkoly

1. implementujte funkci `vector_print(Vector *)`
2. implementujte funkci `vector_ctor(Vector *, unsigned int)`
3. implementujte funkci `vector_init(Vector *)`
4. implementujte funkci `vector_dtor(Vector *)`
5. implementujte funkci `vector_scalar_multiply(Vector *)`
6. implementujte funkci `vector_add(Vector *)`
7. implementujte funkci `vector_sub(Vector *)`
