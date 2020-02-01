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
  $ echo -e '#include <bits/stdc++.h>\nusing namespace std;\ntypedef uint32_t uint;\ntypedef uint64_t uint64;\n\nint main(){\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n    \n    \n    return 0;\n}' > main.cpp
  ```

- Compiling.
  ```
  g++ main.cpp -std=c++14 -Wall
  ```

---

### [AtCoder に登録したら次にやること ～ これだけ解けば十分闘える！過去問精選 10 問 ～](https://qiita.com/drken/items/fd4e5e3630d0f5859067)

| Task                                           | Date       |
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

---

### [AtCoder 版！蟻本 (初級編)](https://qiita.com/drken/items/e77685614f3c6bf86f44)

#### 例題 1-1-1　(ハードルの上がった) くじびき ＜難問！！！！！＞
| Task                                           | Date       |
| ---------------------------------------------- | ---------- |
| JOI 2007 本選 C ダーツ　                        | pass       |

#### 例題 1-6-1　三角形
| Task                                           | Date       |
| ---------------------------------------------- | ---------- |
| ARC 004 A 2点間距離の最大値                      | 2019.11.02 |


#### 例題 1-6-2　
| Task                                           | Date       |
| ---------------------------------------------- | ---------- |
| Ants (POJ No.1852)                             | pass       |
| AGC 013 C Ants on a Circle                     | 2019.11.10: TLE -> pass |

---

### 2 基礎からスタート！ --- 初級編

### 2-1 すべての基本 "全探索"
#### 例題 2-1-1　部分和問題
| Task                                           | Date             |
| ---------------------------------------------- | ---------------- |
| ARC 061 C - たくさんの数式 / Many Formulas      | 2019.11.11 (写経) |
| ABC 079 C - Train Ticket                       | 2019.11.13       |

#### 例題 2-1-2
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| ATC 001 A 深さ優先探索                          | 2019.11.16       | recursive |
|                                                | 2019.11.16       | stuck     |

#### 例題 2-1-3 迷路の最短路
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 007 C 幅優先探索                            | 2019.11.23       | queue     |

#### 例題 2-1-4　特殊な状態の列挙
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 054 C One-stroke Path                      | 2019.11.24 (写経) | recursive |
|                                                | pass             | stuck (単に stuck に積むには，手間が掛かり過ぎる or メモリコピーが多くなるので，pass)． |

### 2-2 猪突猛進！ "貪欲法"
#### 例題 2-2-1　硬貨の問題
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| JOI 2007 予選 A おつり                          | 2019.11.24       |           |

#### 例題 2-2-2　区間スケジューリング問題
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| KUPC 2015 A 東京都                              | 2019.11.25       |           |

#### 例題 2-2-3
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 076 C Dubious Document 2                   | 2019.11.30 (写経) |           |
| ABC 007 B ABC 007 B 辞書式順序                  | 2019.11.30       |           |

#### 例題 2-2-4
| Task                                           | Date             | Note      |
| ---------------------------------------------- | ---------------- | --------- |
| ABC 083 C Multiple Gift                        | 2019.11.30       |           |

#### 例題 2-2-5
AtCoder 上の類題が提示されていないため pass.

---

### 2-3 値を覚えて再利用 "動的計画法"

#### 例題 2-3-1 01ナップサック問題
| Task                                                                       | Date             | Note          |
| -------------------------------------------------------------------------- | ---------------- | ------------- |
| [ABC 015 D 高橋くんの苦悩](https://atcoder.jp/contests/abc015/tasks/abc015_4) | 2019.12.01      | bit 全探索 TLE |
|                                                                             | 2019.12.04      | 再帰 TLE (bit 全探索 よりは速い) |
|                                                                             | 2019.12.04      | memo (118 ms) |
|                                                                             | 2019.12.07      | memo (57 ms) |

#### 例題 2-3-2 最長共通部分列問題
| Task                                                                       | Date             | Note          |
| -------------------------------------------------------------------------- | ---------------- | ------------- |
| [indeedなう C Optimal Recommendations](https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_c) | 2019.12.08 (写経) |               |

#### 例題 2-3-3 個数制限なしナップサック問題
AtCoder 上の類題が提示されていないため pass.

#### 例題 2-3-4 01ナップサック問題その２
| Task                                                                       | Date             | Note          |
| -------------------------------------------------------------------------- | ---------------- | ------------- |
| [ABC 032 D ナップサック問題](https://atcoder.jp/contests/abc032/tasks/abc032_d) | 2019.12.14 (写経) | 84 ms (現状 3 パターンに場合分けしている) |
|                                                                            | 2019.12.19       | 1 ms (分枝限定法．参考 [1]) |

[1] 岩波講座　ソフトウェア科学　３　アルゴリズムとデータ構造　石畑　清（著）

#### 例題 2-3-5 個数制限付き部分和問題
- Task: [Maximum-Cup 2018 D Many Go Round](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d)
- Git dir: [./AtCoder/maxc_2018_d](./AtCoder/maxc_2018_d)

  | Date       | File Name        | Exec Time  | Memory   | References    |
  | ---------- | ---------------- | ----------:| ---------| ------------- |
  | 2019.12.22 | main00_TLE.cpp   | TLE        | 39424 KB	|               |
  | 2019.12.27 | main02_merge.cpp |            |          | [1], [2]      |
  
  [1] 蝶本 第 2 版 page. 62 個数制限付き部分和問題  
  [2] https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

#### 例題 2-3-6 最長増加部分列問題
- Task: [ABC 006 D トランプ挿入ソート](https://atcoder.jp/contests/abc006/tasks/abc006_4)
- Git dir: [./AtCoder/dwacon_04_c](./AtCoder/abc_006_d)

  | Date       | File Name  | Exec Time | Memory | Algorithm | References      |
  | ---------- | ---------- | ---------:| ------:| --------- | --------------- |
  | 2019.12.29 | main01.cpp |   1396 ms | 512 KB | dp 順     | 蟻本 p. 63-64   |
  | 2019.12.31 | main03.cpp |    641 ms | 512 KB | dp 逆順   | 蟻本 p. 64-65   |
  | 2020.01.01 | main04.cpp |      5 ms | 512 KB | 2 分探査  | 蟻本 p. 65       |

#### 例題 2-3-7 分割数
- Task: [第4回 ドワンゴからの挑戦状 予選 C - Kill/Death](https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c)
- Git dir: [./AtCoder/dwacon_04_c](./AtCoder/dwacon_04_c)

  | Date       | File Name        | Exec Time | Memory | Algorithm | References      |
  | ---------- | ---------------- | ---------:| ------:| --------- | --------------- |
  | 2020.01.07 | main_refBase.cpp |      4 ms | 256 KB | dp        | [1], [2], [3]   |
  
  [1] 蟻本 p. 66-67  
  [2] [分割数と、問題まとめ - けんちょんの競プロ精進記録](http://drken1215.hatenablog.com/entry/2018/01/16/222843)  
  [3] [C - Kill/Death: 提出 #3318731 - chocorusk 氏](https://atcoder.jp/contests/dwacon2018-prelims/submissions/3318731)

- Git dir: [./AntsBook/2_3_7](./AntsBook/2_3_7)

  | Date       | File Name        | Algorithm | Note                      |
  | ---------- | ---------------- | --------- | ------------------------- |
  | 2020.01.07 | main01.cpp       | dp        | [1] そのまま．(2 次元配列)   |
  | 2020.01.08 | main02.cpp       | dp        | [1] より改変．(2 次元配列)   |
  | 2020.01.08 | main03.cpp       | dp        | [1] を 1 次元配列に押し込む  |
  | 2020.01.08 | main04.cpp       | dp        | 分岐を削除                 |
  
  [1] 蟻本 p. 66-67  
  
#### 例題 2-3-8 重複組合せ
- Task: [ABC 110 D - Factorization](https://atcoder.jp/contests/abc110/tasks/abc110_d)
- Git dir: [./AtCoder/abc_110_d](./AtCoder/abc_110_d)
  
  | Date       | File Name  | Exec Time | Memory | Algorithm | References      |
  | ---------- | ---------- | ---------:| ------:| --------- | --------------- |
  | 2020.01.27 | main.cpp   |      1 ms | 256 KB |           | [1]             |
  
  [1] [提出 #3251714 - kmjp](https://atcoder.jp/contests/abc110/submissions/3251714)
  
- Git dir: [./AntsBook/2_3_8](./AntsBook/2_3_8)
  
  | Date       | File Name        | Algorithm | Note                      |
  | ---------- | ---------------- | --------- | ------------------------- |
  | 2020.01.12 | main00.cpp       | dp        | [1] そのまま．(2 次元配列)   |
  | 2020.01.12 | main01.cpp       | dp        | [1] より改変．(2 次元配列)   |
  | 2020.01.14 | main02.cpp       | dp        | [1] を 1 次元に押し込めようとしたが，(多分無理)． |
  
  [1] 蟻本 p. 67-68  
  
#### 例題 2-3-9 -> 例題 2-3-18: pass

---

### 2-4 データを工夫して記憶する "データ構造"
#### 2-4-1 Expedition (POJ No.2431)
- Task: [ABC 062 D](https://atcoder.jp/contests/arc074/tasks/arc074_b)

  | Date       | File Name  | Exec Time |  Memory | Algorithm | References      |
  | ---------- | ---------- | ---------:|  ------:| --------- | --------------- |
  | 2020.02.01 | main.cpp   |     54 ms | 4724 KB |           |                 |

### 例題 2-4-2 二分探索木 (set, map の練習)
- Task: [ABC 085 B](https://atcoder.jp/contests/abc085/tasks/abc085_b): already done.
- Task: [ABC 091 B](https://atcoder.jp/contests/abc091/tasks/abc091_b)

  | Date       | File Name  | Exec Time | Memory | Algorithm | References      |
  | ---------- | ---------- | ---------:| ------:| --------- | --------------- |
  |            |            |        ms |     KB |           |                 |

---

#### XXX
- Task: [title](URL)

  | Date       | File Name  | Exec Time | Memory | Algorithm | References      |
  | ---------- | ---------- | ---------:| ------:| --------- | --------------- |
  |            |            |        ms |     KB |           |                 |
