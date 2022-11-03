# 06-02: Předávání parametrů odkazem
V tomto příkladě si vyzkoušíte práci s funkcemi využívající ukazatele v parametrech.


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

1. implementujte funkci `int divide(int, int, double *)`
    - funkce provede výpočet `dividend / divisor` a jeho výsledek vrátí prostřednictvím parametru `quotient`
    - metoda přijímá 3 parametry:
        - dělence (`dividend`),
        - dělitele (`divisor`),
        - ukazatel na podíl/kvocient (`quotient`),
    - metoda vrací hodnotu `1` při úspěšném dělení, `0` jinak
