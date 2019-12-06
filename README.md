# i-am-learning-coding

### Memo
- Including all.
  ```
  #include <bits/stdc++.h>
  ```
- Using directive．
  ```
  using namespace std;
  ```
- For performance.
  ```
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ```
  - ref: [C++の標準入出力についてのメモ](https://hhelibex.hatenablog.jp/entry/2017/10/23/165711)

- Making file.
  ```
  $ echo -e '#include <bits/stdc++.h>\nusing namespace std;\n\nint main(){\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n    \n    \n    return 0;\n}' > main.cpp
  ```

- Compiling.
  ```
  g++ main.cpp -std=c++14 -Wall
  ```

### [AtCoder に登録したら次にやること ～ これだけ解けば十分闘える！過去問精選 10 問 ～](https://qiita.com/drken/items/fd4e5e3630d0f5859067)

| title                                          | date       |
| ---------------------------------------------- | ---------- |
| Hello World --- practice contest               | 2019.10.30 |
| 第 1 問: ABC 086 A - Product (100 点)           | 2019.10.30 |
| 第 2 問: ABC 081 A - Placing Marbles (100 点)   | 2019.10.30 |
| 第 3 問: ABC 081 B - Shift Only (200 点)        | 2019.10.30 |
| 第 4 問: ABC 087 B - Coins (200 点)             | 2019.10.31 |
| 第 5 問: ABC 083 B - Some Sums (200 点)         | 2019.10.31 |
| 第 6 問: ABC 088 B - Card Game for Two (200 点) | 2019.11.01 |
| 第 7 問: ABC 085 B - Kagami Mochi (200 点)      | 2019.11.02 |
| 第 8 問: ABC 085 C - Otoshidama (300 点)        | 2019.11.02 |
| 第 9 問: ABC 049 C - Daydream (300 点)          | 2019.11.02 |
| 第 10 問: ABC 086 C - Traveling (300 点)        | 2019.11.02 |

### [AtCoder 版！蟻本 (初級編)](https://qiita.com/drken/items/e77685614f3c6bf86f44)

#### 例題 1-1-1　(ハードルの上がった) くじびき ＜難問！！！！！＞
| title                                          | date       |
| ---------------------------------------------- | ---------- |
| JOI 2007 本選 C ダーツ　                         | pass       |

#### 例題 1-6-1　三角形
| title                                          | date       |
| ---------------------------------------------- | ---------- |
| ARC 004 A 2点間距離の最大値                       | 2019.11.02 |


#### 例題 1-6-2　
| title                                          | date       |
| ---------------------------------------------- | ---------- |
| Ants (POJ No.1852)                             | pass       |
| AGC 013 C Ants on a Circle                     | 2019.11.10: TLE -> pass |


### 2 基礎からスタート！ --- 初級編

### 2-1 すべての基本 "全探索"
#### 例題 2-1-1　部分和問題
| title                                          | date             |
| ---------------------------------------------- | ---------------- |
| ARC 061 C - たくさんの数式 / Many Formulas       | 2019.11.11 (写経) |
| ABC 079 C - Train Ticket                       | 2019.11.13       |

#### 例題 2-1-2
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| ATC 001 A 深さ優先探索                           | 2019.11.16       | recursive |
|                                                | 2019.11.16       | stuck     |

#### 例題 2-1-3 迷路の最短路
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 007 C 幅優先探索                             | 2019.11.23       | queue     |

#### 例題 2-1-4　特殊な状態の列挙
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 054 C One-stroke Path                      | 2019.11.24 (写経) | recursive |
|                                                | pass             | stuck (単に stuck に積むには，手間が掛かり過ぎる or メモリコピーが多くなるので，pass)． |

### 2-2 猪突猛進！ "貪欲法"
#### 例題 2-2-1　硬貨の問題
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| JOI 2007 予選 A おつり                           | 2019.11.24       |           |

#### 例題 2-2-2　区間スケジューリング問題
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| KUPC 2015 A 東京都                              | 2019.11.25       |           |

#### 例題 2-2-3
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 076 C Dubious Document 2                   | 2019.11.30 (写経) |           |
| ABC 007 B ABC 007 B 辞書式順序                   | 2019.11.30       |           |

#### 例題 2-2-4
| title                                          | date             | note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 083 C Multiple Gift                        | 2019.11.30       |           |

#### 例題 2-2-5
AtCoder 上で類題がないため pass.

### 2-3 値を覚えて再利用 "動的計画法"

#### 例題 2-3-1 01ナップサック問題
| title                                                                      | date             | note          |
| -------------------------------------------------------------------------- | ---------------- | ------------- |
| [ABC 015 D 高橋くんの苦悩](https://atcoder.jp/contests/abc015/tasks/abc015_4) | 2019.12.01      | bit 全探索 TLE |
|                                                                             | 2019.12.04      | 再帰 TLE (bit 全探索 よりは速い) |
|                                                                             | 2019.12.04      | memo (118 ms) |
|                                                                             | 2019.12.07      | memo (57 ms) |

#### 例題 2-3-2 最長共通部分列問題
| title                                                                      | date             | note          |
| -------------------------------------------------------------------------- | ---------------- | ------------- |
| [ndeedなう C Optimal Recommendations](https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_c) |                  |               |
