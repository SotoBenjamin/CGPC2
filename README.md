# CGPC2
PC2 

## Test Hull 
### Points inside a circle
| Size     | Alg    | Prefilter | Time (ms) |
|----------|--------|-----------|-----------|
| 1000     | Graham | no        | 0.752     |
| 1000     | Graham | si        | 0.362     |
| 1000     | Jarvis | no        | 0.901     |
| 1000     | Jarvis | si        | 0.400     |
| 10000    | Graham | no        | 7.353     |
| 10000    | Graham | si        | 2.879     |
| 10000    | Jarvis | no        | 13.144    |
| 10000    | Jarvis | si        | 3.941     |
| 100000   | Graham | no        | 47.207    |
| 100000   | Graham | si        | 19.038    |
| 100000   | Jarvis | no        | 178.781   |
| 100000   | Jarvis | si        | 50.398    |
| 1000000  | Graham | no        | 517.872   |
| 1000000  | Graham | si        | 197.185   |
| 1000000  | Jarvis | no        | 3683.033  |
| 1000000  | Jarvis | si        | 855.655   |
| 2000000  | Graham | no        | 1087.762  |
| 2000000  | Graham | si        | 414.063   |
| 2000000  | Jarvis | no        | 9427.258  |
| 2000000  | Jarvis | si        | 2172.716  |
| 5000000  | Graham | no        | 2834.430  |
| 5000000  | Graham | si        | 1047.042  |
| 5000000  | Jarvis | no        | 35117.648 |
| 5000000  | Jarvis | si        | 7762.541  |
### Points i border circle
| Size     | Alg    | Prefilter | Time (ms)   |
|----------|--------|-----------|-------------|
| 1000     | Graham | no        | 0.910       |
| 1000     | Graham | si        | 1.169       |
| 1000     | Jarvis | no        | 21.902      |
| 1000     | Jarvis | si        | 17.771      |
| 10000    | Graham | no        | 5.748       |
| 10000    | Graham | si        | 7.049       |
| 10000    | Jarvis | no        | 1359.479    |
| 10000    | Jarvis | si        | 1364.567    |
| 100000   | Graham | no        | 56.178      |
| 100000   | Graham | si        | 66.600      |
| 100000   | Jarvis | no        | 133848.769  |
| 100000   | Jarvis | si        | 134853.220  |
| 1000000  | Graham | no        | 628.874     |
| 1000000  | Graham | si        | 738.367     |
| 1000000  | Jarvis | no        | ∞           |
| 1000000  | Jarvis | si        | ∞           |
| 2000000  | Graham | no        | 1328.913    |
| 2000000  | Graham | si        | 1519.368    |
| 2000000  | Jarvis | no        | ∞           |
| 2000000  | Jarvis | si        | ∞           |
| 5000000  | Graham | no        | 3513.505    |
| 5000000  | Graham | si        | 4094.580    |
| 5000000  | Jarvis | no        | ∞           |
| 5000000  | Jarvis | si        | ∞           |
### Points inside Rectangle
| Size     | Alg    | Prefilter | Time (ms) |
|----------|--------|-----------|-----------|
| 1000     | Graham | no        | 0.752     |
| 1000     | Graham | si        | 0.499     |
| 1000     | Jarvis | no        | 0.523     |
| 1000     | Jarvis | si        | 0.419     |
| 10000    | Graham | no        | 7.477     |
| 10000    | Graham | si        | 4.548     |
| 10000    | Jarvis | no        | 5.868     |
| 10000    | Jarvis | si        | 4.211     |
| 100000   | Graham | no        | 49.325    |
| 100000   | Graham | si        | 41.489    |
| 100000   | Jarvis | no        | 55.628    |
| 100000   | Jarvis | si        | 47.825    |
| 1000000  | Graham | no        | 503.735   |
| 1000000  | Graham | si        | 185.905   |
| 1000000  | Jarvis | no        | 605.519   |
| 1000000  | Jarvis | si        | 213.495   |
| 2000000  | Graham | no        | 1053.107  |
| 2000000  | Graham | si        | 635.806   |
| 2000000  | Jarvis | no        | 1322.058  |
| 2000000  | Jarvis | si        | 749.932   |
| 5000000  | Graham | no        | 2795.111  |
| 5000000  | Graham | si        | 1242.706  |
| 5000000  | Jarvis | no        | 2873.801  |
| 5000000  | Jarvis | si        | 1289.481  |
### Points in Border Rectangle
| Size     | Alg    | Prefilter | Time (ms) |
|----------|--------|-----------|-----------|
| 1000     | Graham | no        | 0.689     |
| 1000     | Graham | si        | 0.973     |
| 1000     | Jarvis | no        | 0.505     |
| 1000     | Jarvis | si        | 0.702     |
| 10000    | Graham | no        | 6.418     |
| 10000    | Graham | si        | 8.169     |
| 10000    | Jarvis | no        | 3.606     |
| 10000    | Jarvis | si        | 5.534     |
| 100000   | Graham | no        | 44.742    |
| 100000   | Graham | si        | 57.090    |
| 100000   | Jarvis | no        | 26.187    |
| 100000   | Jarvis | si        | 43.146    |
| 1000000  | Graham | no        | 477.391   |
| 1000000  | Graham | si        | 642.431   |
| 1000000  | Jarvis | no        | 269.219   |
| 1000000  | Jarvis | si        | 436.569   |
| 2000000  | Graham | no        | 1006.299  |
| 2000000  | Graham | si        | 1352.270  |
| 2000000  | Jarvis | no        | 564.824   |
| 2000000  | Jarvis | si        | 862.262   |
| 5000000  | Graham | no        | 2773.302  |
| 5000000  | Graham | si        | 3498.197  |
| 5000000  | Jarvis | no        | 1475.239  |
| 5000000  | Jarvis | si        | 2216.309  |
### Points Interior Parabola
| Size     | Alg    | Prefilter | Time (ms)  |
|----------|--------|-----------|------------|
| 1000     | Graham | no        | 0.746      |
| 1000     | Graham | si        | 0.697      |
| 1000     | Jarvis | no        | 0.630      |
| 1000     | Jarvis | si        | 0.563      |
| 10000    | Graham | no        | 7.354      |
| 10000    | Graham | si        | 6.077      |
| 10000    | Jarvis | no        | 5.816      |
| 10000    | Jarvis | si        | 5.403      |
| 100000   | Graham | no        | 76.949     |
| 100000   | Graham | si        | 44.589     |
| 100000   | Jarvis | no        | 52.515     |
| 100000   | Jarvis | si        | 48.720     |
| 1000000  | Graham | no        | 479.149    |
| 1000000  | Graham | si        | 348.972    |
| 1000000  | Jarvis | no        | 1963.635   |
| 1000000  | Jarvis | si        | 1156.567   |
| 2000000  | Graham | no        | 999.636    |
| 2000000  | Graham | si        | 692.402    |
| 2000000  | Jarvis | no        | 6741.894   |
| 2000000  | Jarvis | si        | 3741.215   |
| 5000000  | Graham | no        | 2628.949   |
| 5000000  | Graham | si        | 1934.486   |
| 5000000  | Jarvis | no        | 43717.250  |
| 5000000  | Jarvis | si        | 25716.280  |