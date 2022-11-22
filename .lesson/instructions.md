# 08-01: Dynamická alokace paměti
V tomto cvičení si vyzkoušíte pokročilejší práci s dynamickou pamětí. K funkcím z minulého cvičení přidáme ještě funkci pro realokaci paměti - `realloc` 

Pro připomenutí:

`void *malloc(size_t size)`
 - alokuje požadovanou pamět o velikosti `size` na heapu a vrací pointer na tuto pamět nebo NULL, pokud alokace selhala.
 - alternativou může být volání funkce [`calloc`](https://linux.die.net/man/3/calloc), která navíc paměť nuluje.

 `void free(void *ptr)`
 - dealokuje pamět, která byla dříve alokována pomocí funkce `malloc`, `calloc` či `realloc` (viz. dále). Vstupem do této funkce je pointer na alokovanou paměť, kterou chceme dealokovat.

Nově použijeme i funkci:

 `void *realloc(void *ptr, size_t size)`
 - mění velikost alokované paměti, která byla dříve alokována pomocí funkce `malloc` nebo `calloc`. Vstupem je pointer `ptr` na dříve alokovanou pamět, kterou chceme zvětšit nebo zmenšit a dále pak nová velikost alokované paměti `size`.

## Vektory

Úvod do vektorů a operací nad nimi můžete najít na [Math Insight][intro].
Další obecné informace máte k dispozici také na [Wiki][wiki].
Ukázky řešení operací s vektory pak můžete najít na [WolframAlpha][wolfram].

[intro]: https://mathinsight.org/vector_introduction "Math Insight - Vector Introduction"
[wolfram]: https://www.wolframalpha.com/examples/mathematics/linear-algebra/vectors/ "WolframAlpha Vectors"
[wiki]: https://en.wikipedia.org/wiki/Vector_(mathematics_and_physics) "Wikipedia Vectors"

---

## Úkoly
1. Implementujte funkci:

    ```C
    /**
    * Provede změnu velikosti alokované paměti na heapu. Pokud je nová velikost nulová,
    * je paměť dealokována a funkce vrací NULL. Pokud je ukazatel na existující paměť NULL,
    * je alokován nový blok paměti. V případě že je pointer na paměť NULL a zároveň je 
    * požadovaná velikost 0, funkce vrací NULL bez jakékoliv alokace.
    * 
    * @param arr ukazatel na existující alokovanou paměť
    * @param new_size nová velikost paměti v prvcích INT
    * 
    * @returns pointer na nově alokovaný vector v případě úspěšné alokace, NULL jinak
    * 
    * hint: realloc, sizeof
    */
    int *resize(int *arr, unsigned int new_size);
    ```

2. Implementujte funkce pro práci s vektory:

    ```C
    /**
    * Dynamicky alokuje nový vektor o nulové délce na heapu, pointer na složky (komponenty) vektoru
    * nastavuje na NULL.
    * 
    * @returns pointer na nově alokovaný vector v případě úspěšné alokace, NULL jinak
    * 
    * hint: malloc, sizeof
    */
    Vector *vector_ctor();
    ```
    ```C
    /**
    * Provede zrušení (uvolnění alokované paměti) daného vektoru a to jak jeho prvků,
    * tak vektoru samotného. Ukazatel na vektor pak nastavuje na NULL.
    * 
    * @param v ukazatel na existující vektor
    * 
    * hint: free
    */
    void vector_dtor(Vector *vector);
    ```
    ```C
    /**
    *  Přidá do vektoru jednu novou složku (komponenetu) a vektor automaticky rozšíří.
    * 
    * @param v       ukazatel na existující vektor
    * @param value   hodnota, která má být přidána do vektoru
    * 
    * @returns hodnotu 1 v případě úspěšného přidání složky do vektoru, 0 jinak
    * 
    * hint: vaše funkce resize
    */
    int vector_add(Vector *vec, int value);
    ```
3. Implementujte vypisovací funkci:

    ```C
    /**
    * Vytiskne vektor (velikost a jeho prvky) na standardní výstup.
    * 
    * @param v  ukazatel na vektor
    */
    void vector_print(Vector *v);
    ```
    
4. Ve funkci `main` implementujte:

    1. V nekonečném cyklu čtete nenulové celočíselné hodnoty a jednotlivě je přidávejte do vektoru. Nulová hodnota ukončuje čtecí cyklus. 
    2. Vypište uživateli na _stdout_ obsah vektoru a jeho celkovou velikost voláním `vector_print`.
    3. Uvolněte zabranou paměť.
    
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
