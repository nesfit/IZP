# 08-02: Nahrazení podřetězců
V tomto cvičení budete dále pracovat s dynamickou pamětí a vyzkoušíte si konkrétní použití.

Pro připomenutí:

`void *malloc(size_t size)`
 - alokuje požadovanou pamět o velikosti `size` na heapu a vrací pointer na tuto pamět nebo NULL, pokud alokace selhala.
 - alternativou může být volání funkce [`calloc`](https://linux.die.net/man/3/calloc), která navíc paměť nuluje.

 `void free(void *ptr)`
 - dealokuje pamět, která byla dříve alokována pomocí funkce `malloc`, `calloc` či `realloc` (viz. dále). Vstupem do této funkce je pointer na alokovanou paměť, kterou chceme dealokovat.

 `void *realloc(void *ptr, size_t size)`
 - mění velikost alokované paměti, která byla dříve alokována pomocí funkce `malloc` nebo `calloc`. Vstupem je pointer `ptr` na dříve alokovanou pamět, kterou chceme zvětšit nebo zmenšit a dále pak nová velikost alokované paměti `size`. Pokud je nová velikost paměti nulová, je paměť uvolněna (stejně jako při volání `free`) a pokud je hodnota `ptr` NULL, je alokována nová paměť.

## Podřetězce

S podřetězci jste se již seznámili dříve při práci s funkcemi z `string.h`. Pro připomenutí:
```C
char *str = "abcdefghi"; //rětězec o délce 9, v paměti zabírá ovšem 10B (+ '\0' )
```
Řetězec `str` obsahuje například podřetězce `abcdefghi`, `a`, `abcd` ale neobsahuje například podřetězec `acdef`.  

Výsledek nahrazení v řetezci `abcdefghi` podřetězce `bc` za `XYZ` je `aXYZdefghi`. Všiměte si, že pokud je nahrazovaný podřetězec stejně dlouhý jako nahrazující, je oprace triviální. V případech kdy by nahrazující řetězec byl delší, je potřeba pracovat s dynamickou pamětí.

---
*Všechny funkce ze* `string.h` *jsou zakázané*.

## Úkoly
1. Implementujte funkce:
    ```c
    size_t str_len(char *str);

    void mem_cpy(void *dest, void *src, size_t n);
    
    int find_substr(char *str, char *substr);
    
    void replace_same_length(char *str, char *substr, char *new_substr);
    
    char *replace(char *str, char *substr, char *new_substr);
    ```    
4. Ve funkci `main` zavolejte své funkce a otestujte jejich funkčnost.

---

## `Makefile` recepty

Recepty spustitelné z příkazové řádky prostřednictvím příkazu `make $RECIPE`.

| Název receptu | Popis obsahu                                                |
| ------------- | ----------------------------------------------------------- |
| `main`        | Kompilace vašeho programu
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
