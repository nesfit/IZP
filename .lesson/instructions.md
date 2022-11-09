# 07-03: Dynamická alokace paměti
V tomto cvičení si vyzkoušíte práci s dynamickou alokací paměti na příkladu implementace funkcí pro práci s vektory.

Jednotlivé úkoly najdete přímo v kódu.

## Vektory

Úvod do vektorů a operací nad nimi můžete najít na [Math Insight][intro].
Další obecné informace máte k dispozici také na [Wiki][wiki].
Ukázky řešení operací s vektory pak můžete najít na [WolframAlpha][wolfram].

[intro]: https://mathinsight.org/vector_introduction "Math Insight - Vector Introduction"
[wolfram]: https://www.wolframalpha.com/examples/mathematics/linear-algebra/vectors/ "WolframAlpha Vectors"
[wiki]: https://en.wikipedia.org/wiki/Vector_(mathematics_and_physics) "Wikipedia Vectors"

---

## `Makefile` recepty

Recepty spustitelné z příkazové řádky prostřednictvím příkazu `make $RECIPE`.

| Název receptu | Popis obsahu                                                |
| ------------- | ----------------------------------------------------------- |
|               | Kompilace vašeho programu
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
