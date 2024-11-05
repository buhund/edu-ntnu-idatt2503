#  IDATT2503 - Cryptography - Crypto Assignment 1



## Problem 01

b) Calculate −99 mod 1001 = 902

c) Calculate 232 + 22 · 77 − 183 mod 8 = 7

d) Determine if 55 ≡ 77 (mod 12) = False



```python
# Problem 1b: Calculate −99 mod 1001
mod_b = (-99) % 1001

# Problem 1c: Calculate 232 + 22 · 77 − 183 mod 8
mod_c = (232 + 22 * 77 - 183) % 8

# Problem 1d: Determine if 55 ≡ 77 (mod 12)
mod_d = (55 % 12 == 77 % 12)

mod_b, mod_c, mod_d
```



## Problem 02

A number $a ∈ Z_n$ , i.e. an integer modulo $n$, has a multiplicative inverse if there exists $b ∈ Z_n$ such that $ab ≡ 1 (mod \space n)$.

**a) Write the multiplication table of the elements of $Z_{12}$, excluding the 0 element.**

```python
Multiplication Table for Z12
0	1	2	3	4	5	6	7	8	9	10
1	2	3	4	5	6	7	8	9	10	11
2	4	6	8	10	0	2	4	6	8	10
3	6	9	0	3	6	9	0	3	6	9
4	8	0	4	8	0	4	8	0	4	8
5	10	3	8	1	6	11	4	9	2	7
6	0	6	0	6	0	6	0	6	0	6
7	2	9	4	11	6	1	8	3	10	5
8	4	0	8	4	0	8	4	0	8	4
9	6	3	0	9	6	3	0	9	6	3
10	8	6	4	2	0	10	8	6	4	2
11	10	9	8	7	6	5	4	3	2	1
```



**b) Which integers have a multiplicative inverse modulo 12?**

```python
[1, 5, 7, 11]
```



**c) Do the same for $Z_{11}$ . Which numbers have mult.inverse $mod \space 11$?**

````python
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
````



**d) Find the multiplicative inverse to $11 \space modulo \space 29$ by trial and error, ie. just try different values.**

```
([1, 5, 7, 11], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 8)
```



**e) Formulate a condition for a to have a multiplicative inverse modulo $n$**. 

​	Hint: It involves the factorisations of $a$ and $n$.

An integer $a \in Z_n$ has a multiplicative inverse modulo $n$ if and only if $\gcd(a, n) = 1$, i.e. $a$ and $n$ are coprime. 



## Problem 03 – Affine ciphers


We use small letters a-z for plain text, and cipher texts with capital letters, to distinguish the plain texts from cipherstext, but they represent the same alphabet, i.e. there are 26 letters. We enocde the letters with numbers from 0 to 25, consideres as elements in $Z_{26}$ , the integers modulo $26$.

The function $e_k : Z_{26} \rarr Z_{26}$ is given by the formula
$$
e_k(x) = (3 \cdot x + 11) \space mod \space 26
$$
The key is the pair $k = (3, 11)$



**a) Write $e_k$ as a permutation, i.e. the sequence of letters we get when encrypting $a$, $b$, $c$ etc.**
$$
’a’→’L’,’b’→’O’,’c’→’R’,…,’z’→’I’
$$


Thus, the sequence of letters we get when encrypting $\{a, b, c, \dots, z\}$ is:
$$
\text{LORUXADGJMPSVYBEHKNQTWZCFI}
$$




**b) Use $e_k$ to encrypt the message `m = ’alice’`**


$$
m=\text{’LSJRX’}
$$




**c) Find the inverse of $e_k$ as a:**
– permutation as in part a)
– as a formula $d_k(y) = ay + b (mod 26)$ (the decryption) where you have to determine $a$ and $b$.
Hint: Invert the formula for $e_k$ , where you need to use a multiplicative inverse.



**d) Use the inverse d to decrypt $c = RBKKXRQ$**

As a permutation, the decryption function reverses the encryption. Decrypted message:
$$
\text{RBKKXRQ} \rarr \text{correct}
$$
As a formula, the decryption function  $d_k(y) = a \cdot (y - b) \mod 26$ is:
$$
d_k(y) = 9 \cdot (y - 11) \mod 26
$$
where 9 is the multiplicative inverse of $3 \mod 26$.



**e) How secure is this cipher, compared to a rotation cipher? Consider both brute force and known plaintext attacks.**

Brute Force Attack:

- In a rotation cipher, there are only 26 possible keys, one for each shift. This makes it vulnerable to brute force attacks, since an attacker easily can run through all possible shifts.
- In an affine cipher, the number of keys is larger, because it involves two variables, $a$ and $b$, where $a$ must be coprime with 26. While it's still vulnerable to brute force attacks, the increased number of keys makes it more secure than the rotation cipher.

Known Plaintext Attack

- Both of the ciphers are vulnerable to know plaintext attacks, but if the attacker can learn one or two pairs of plaintext and ciphertext, this could allow the attacker to deduce the key through solving a system of equations. On the other side, the increased keyspace from using the two variables, one of which must be coprime with 26, provides some additional difficulty to the attack.



**f) How many legal keys does are there for this choice of formula and alphabet?**

For an affine cipher with the formula $e_k(x) = (a \cdot x + b) \mod 26$:

- $a$ must be coprime with 26, meaning it can take values from the set $\{1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25\}$, which has 12 elements.
- $b$ can take any value from 0 to 25, which gives 26 possibilities.

That makes the total number of legal keys:
$$
12 \cdot 26 = 312 \text{ keys}
$$




## Problem 04

You (an eavesdropper) see the following message from Alice to Bob (Only letters are included, and then grouped into fives):
$$
\text{RGMRQ ERQMZ MZXMD ENNZU QFD}
$$


You know they use a affine cipher. Use brute force to find plain text and key.

**Answer:**

As established in the above problems, the encryption formula for an affine cipher is
$$
e_k(x) = (a \cdot x + b) \space mod \space 26
$$
where $a$ must be coprime with 26. This limits the possible values for $a$:
$$
\text{1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25}
$$
In addition, $b$ can only be a value between 0 and 25.

A brute force attack would then consist of iterating through all valid values of $a$ and $b$, as defined above, to decrypt the message.

Using Python to write the code for brute forcing the encryption, the output is as follows:

```
Key (a=1, b=0) -> Decrypted Text: RGMRQERQMZMZXMDENNZUQFD
Key (a=1, b=1) -> Decrypted Text: QFLQPDQPLYLYWLCDMMYTPEC
Key (a=1, b=2) -> Decrypted Text: PEKPOCPOKXKXVKBCLLXSODB
Key (a=1, b=3) -> Decrypted Text: ODJONBONJWJWUJABKKWRNCA
Key (a=1, b=4) -> Decrypted Text: NCINMANMIVIVTIZAJJVQMBZ
Key (a=1, b=5) -> Decrypted Text: MBHMLZMLHUHUSHYZIIUPLAY
Key (a=1, b=6) -> Decrypted Text: LAGLKYLKGTGTRGXYHHTOKZX
Key (a=1, b=7) -> Decrypted Text: KZFKJXKJFSFSQFWXGGSNJYW
Key (a=1, b=8) -> Decrypted Text: JYEJIWJIERERPEVWFFRMIXV
Key (a=1, b=9) -> Decrypted Text: IXDIHVIHDQDQODUVEEQLHWU
Key (a=1, b=10) -> Decrypted Text: HWCHGUHGCPCPNCTUDDPKGVT
Key (a=1, b=11) -> Decrypted Text: GVBGFTGFBOBOMBSTCCOJFUS
Key (a=1, b=12) -> Decrypted Text: FUAFESFEANANLARSBBNIETR
Key (a=1, b=13) -> Decrypted Text: ETZEDREDZMZMKZQRAAMHDSQ
Key (a=1, b=14) -> Decrypted Text: DSYDCQDCYLYLJYPQZZLGCRP
Key (a=1, b=15) -> Decrypted Text: CRXCBPCBXKXKIXOPYYKFBQO
Key (a=1, b=16) -> Decrypted Text: BQWBAOBAWJWJHWNOXXJEAPN
Key (a=1, b=17) -> Decrypted Text: APVAZNAZVIVIGVMNWWIDZOM
Key (a=1, b=18) -> Decrypted Text: ZOUZYMZYUHUHFULMVVHCYNL
Key (a=1, b=19) -> Decrypted Text: YNTYXLYXTGTGETKLUUGBXMK
Key (a=1, b=20) -> Decrypted Text: XMSXWKXWSFSFDSJKTTFAWLJ
Key (a=1, b=21) -> Decrypted Text: WLRWVJWVRERECRIJSSEZVKI
Key (a=1, b=22) -> Decrypted Text: VKQVUIVUQDQDBQHIRRDYUJH
Key (a=1, b=23) -> Decrypted Text: UJPUTHUTPCPCAPGHQQCXTIG
Key (a=1, b=24) -> Decrypted Text: TIOTSGTSOBOBZOFGPPBWSHF
Key (a=1, b=25) -> Decrypted Text: SHNSRFSRNANAYNEFOOAVRGE
Key (a=3, b=0) -> Decrypted Text: XCEXOKXOERERZEBKNNRYOTB
Key (a=3, b=1) -> Decrypted Text: OTVOFBOFVIVIQVSBEEIPFKS
Key (a=3, b=2) -> Decrypted Text: FKMFWSFWMZMZHMJSVVZGWBJ
Key (a=3, b=3) -> Decrypted Text: WBDWNJWNDQDQYDAJMMQXNSA
Key (a=3, b=4) -> Decrypted Text: NSUNEANEUHUHPURADDHOEJR
Key (a=3, b=5) -> Decrypted Text: EJLEVREVLYLYGLIRUUYFVAI
Key (a=3, b=6) -> Decrypted Text: VACVMIVMCPCPXCZILLPWMRZ
Key (a=3, b=7) -> Decrypted Text: MRTMDZMDTGTGOTQZCCGNDIQ
Key (a=3, b=8) -> Decrypted Text: DIKDUQDUKXKXFKHQTTXEUZH
Key (a=3, b=9) -> Decrypted Text: UZBULHULBOBOWBYHKKOVLQY
Key (a=3, b=10) -> Decrypted Text: LQSLCYLCSFSFNSPYBBFMCHP
Key (a=3, b=11) -> Decrypted Text: CHJCTPCTJWJWEJGPSSWDTYG
Key (a=3, b=12) -> Decrypted Text: TYATKGTKANANVAXGJJNUKPX
Key (a=3, b=13) -> Decrypted Text: KPRKBXKBREREMROXAAELBGO
Key (a=3, b=14) -> Decrypted Text: BGIBSOBSIVIVDIFORRVCSXF
Key (a=3, b=15) -> Decrypted Text: SXZSJFSJZMZMUZWFIIMTJOW
Key (a=3, b=16) -> Decrypted Text: JOQJAWJAQDQDLQNWZZDKAFN
Key (a=3, b=17) -> Decrypted Text: AFHARNARHUHUCHENQQUBRWE
Key (a=3, b=18) -> Decrypted Text: RWYRIERIYLYLTYVEHHLSINV
Key (a=3, b=19) -> Decrypted Text: INPIZVIZPCPCKPMVYYCJZEM
Key (a=3, b=20) -> Decrypted Text: ZEGZQMZQGTGTBGDMPPTAQVD
Key (a=3, b=21) -> Decrypted Text: QVXQHDQHXKXKSXUDGGKRHMU
Key (a=3, b=22) -> Decrypted Text: HMOHYUHYOBOBJOLUXXBIYDL
Key (a=3, b=23) -> Decrypted Text: YDFYPLYPFSFSAFCLOOSZPUC
Key (a=3, b=24) -> Decrypted Text: PUWPGCPGWJWJRWTCFFJQGLT
Key (a=3, b=25) -> Decrypted Text: GLNGXTGXNANAINKTWWAHXCK
Key (a=5, b=0) -> Decrypted Text: TWSTYGTYSFSFPSLGNNFEYBL
Key (a=5, b=1) -> Decrypted Text: YBXYDLYDXKXKUXQLSSKJDGQ
Key (a=5, b=2) -> Decrypted Text: DGCDIQDICPCPZCVQXXPOILV
Key (a=5, b=3) -> Decrypted Text: ILHINVINHUHUEHAVCCUTNQA
Key (a=5, b=4) -> Decrypted Text: NQMNSANSMZMZJMFAHHZYSVF
Key (a=5, b=5) -> Decrypted Text: SVRSXFSXREREORKFMMEDXAK
Key (a=5, b=6) -> Decrypted Text: XAWXCKXCWJWJTWPKRRJICFP
Key (a=5, b=7) -> Decrypted Text: CFBCHPCHBOBOYBUPWWONHKU
Key (a=5, b=8) -> Decrypted Text: HKGHMUHMGTGTDGZUBBTSMPZ
Key (a=5, b=9) -> Decrypted Text: MPLMRZMRLYLYILEZGGYXRUE
Key (a=5, b=10) -> Decrypted Text: RUQRWERWQDQDNQJELLDCWZJ
Key (a=5, b=11) -> Decrypted Text: WZVWBJWBVIVISVOJQQIHBEO
Key (a=5, b=12) -> Decrypted Text: BEABGOBGANANXATOVVNMGJT
Key (a=5, b=13) -> Decrypted Text: GJFGLTGLFSFSCFYTAASRLOY
Key (a=5, b=14) -> Decrypted Text: LOKLQYLQKXKXHKDYFFXWQTD
Key (a=5, b=15) -> Decrypted Text: QTPQVDQVPCPCMPIDKKCBVYI
Key (a=5, b=16) -> Decrypted Text: VYUVAIVAUHUHRUNIPPHGADN
Key (a=5, b=17) -> Decrypted Text: ADZAFNAFZMZMWZSNUUMLFIS
Key (a=5, b=18) -> Decrypted Text: FIEFKSFKERERBEXSZZRQKNX
Key (a=5, b=19) -> Decrypted Text: KNJKPXKPJWJWGJCXEEWVPSC
Key (a=5, b=20) -> Decrypted Text: PSOPUCPUOBOBLOHCJJBAUXH
Key (a=5, b=21) -> Decrypted Text: UXTUZHUZTGTGQTMHOOGFZCM
Key (a=5, b=22) -> Decrypted Text: ZCYZEMZEYLYLVYRMTTLKEHR
Key (a=5, b=23) -> Decrypted Text: EHDEJREJDQDQADWRYYQPJMW
Key (a=5, b=24) -> Decrypted Text: JMIJOWJOIVIVFIBWDDVUORB
Key (a=5, b=25) -> Decrypted Text: ORNOTBOTNANAKNGBIIAZTWG
Key (a=7, b=0) -> Decrypted Text: VMYVGIVGYLYLHYTINNLOGXT
Key (a=7, b=1) -> Decrypted Text: GXJGRTGRJWJWSJETYYWZRIE
Key (a=7, b=2) -> Decrypted Text: RIURCERCUHUHDUPEJJHKCTP
Key (a=7, b=3) -> Decrypted Text: CTFCNPCNFSFSOFAPUUSVNEA
Key (a=7, b=4) -> Decrypted Text: NEQNYANYQDQDZQLAFFDGYPL
Key (a=7, b=5) -> Decrypted Text: YPBYJLYJBOBOKBWLQQORJAW
Key (a=7, b=6) -> Decrypted Text: JAMJUWJUMZMZVMHWBBZCULH
Key (a=7, b=7) -> Decrypted Text: ULXUFHUFXKXKGXSHMMKNFWS
Key (a=7, b=8) -> Decrypted Text: FWIFQSFQIVIVRIDSXXVYQHD
Key (a=7, b=9) -> Decrypted Text: QHTQBDQBTGTGCTODIIGJBSO
Key (a=7, b=10) -> Decrypted Text: BSEBMOBMERERNEZOTTRUMDZ
Key (a=7, b=11) -> Decrypted Text: MDPMXZMXPCPCYPKZEECFXOK
Key (a=7, b=12) -> Decrypted Text: XOAXIKXIANANJAVKPPNQIZV
Key (a=7, b=13) -> Decrypted Text: IZLITVITLYLYULGVAAYBTKG
Key (a=7, b=14) -> Decrypted Text: TKWTEGTEWJWJFWRGLLJMEVR
Key (a=7, b=15) -> Decrypted Text: EVHEPREPHUHUQHCRWWUXPGC
Key (a=7, b=16) -> Decrypted Text: PGSPACPASFSFBSNCHHFIARN
Key (a=7, b=17) -> Decrypted Text: ARDALNALDQDQMDYNSSQTLCY
Key (a=7, b=18) -> Decrypted Text: LCOLWYLWOBOBXOJYDDBEWNJ
Key (a=7, b=19) -> Decrypted Text: WNZWHJWHZMZMIZUJOOMPHYU
Key (a=7, b=20) -> Decrypted Text: HYKHSUHSKXKXTKFUZZXASJF
Key (a=7, b=21) -> Decrypted Text: SJVSDFSDVIVIEVQFKKILDUQ
Key (a=7, b=22) -> Decrypted Text: DUGDOQDOGTGTPGBQVVTWOFB
Key (a=7, b=23) -> Decrypted Text: OFROZBOZREREARMBGGEHZQM
Key (a=7, b=24) -> Decrypted Text: ZQCZKMZKCPCPLCXMRRPSKBX
Key (a=7, b=25) -> Decrypted Text: KBNKVXKVNANAWNIXCCADVMI
Key (a=9, b=0) -> Decrypted Text: ZSKZWMZWKXKXRKJMNNXIWPJ
Key (a=9, b=1) -> Decrypted Text: WPHWTJWTHUHUOHGJKKUFTMG
Key (a=9, b=2) -> Decrypted Text: TMETQGTQERERLEDGHHRCQJD
Key (a=9, b=3) -> Decrypted Text: QJBQNDQNBOBOIBADEEOZNGA
Key (a=9, b=4) -> Decrypted Text: NGYNKANKYLYLFYXABBLWKDX
Key (a=9, b=5) -> Decrypted Text: KDVKHXKHVIVICVUXYYITHAU
Key (a=9, b=6) -> Decrypted Text: HASHEUHESFSFZSRUVVFQEXR
Key (a=9, b=7) -> Decrypted Text: EXPEBREBPCPCWPORSSCNBUO
Key (a=9, b=8) -> Decrypted Text: BUMBYOBYMZMZTMLOPPZKYRL
Key (a=9, b=9) -> Decrypted Text: YRJYVLYVJWJWQJILMMWHVOI
Key (a=9, b=10) -> Decrypted Text: VOGVSIVSGTGTNGFIJJTESLF
Key (a=9, b=11) -> Decrypted Text: SLDSPFSPDQDQKDCFGGQBPIC
Key (a=9, b=12) -> Decrypted Text: PIAPMCPMANANHAZCDDNYMFZ
Key (a=9, b=13) -> Decrypted Text: MFXMJZMJXKXKEXWZAAKVJCW
Key (a=9, b=14) -> Decrypted Text: JCUJGWJGUHUHBUTWXXHSGZT
Key (a=9, b=15) -> Decrypted Text: GZRGDTGDREREYRQTUUEPDWQ
Key (a=9, b=16) -> Decrypted Text: DWODAQDAOBOBVONQRRBMATN
Key (a=9, b=17) -> Decrypted Text: ATLAXNAXLYLYSLKNOOYJXQK
Key (a=9, b=18) -> Decrypted Text: XQIXUKXUIVIVPIHKLLVGUNH
Key (a=9, b=19) -> Decrypted Text: UNFURHURFSFSMFEHIISDRKE
Key (a=9, b=20) -> Decrypted Text: RKCROEROCPCPJCBEFFPAOHB
Key (a=9, b=21) -> Decrypted Text: OHZOLBOLZMZMGZYBCCMXLEY
Key (a=9, b=22) -> Decrypted Text: LEWLIYLIWJWJDWVYZZJUIBV
Key (a=9, b=23) -> Decrypted Text: IBTIFVIFTGTGATSVWWGRFYS
Key (a=9, b=24) -> Decrypted Text: FYQFCSFCQDQDXQPSTTDOCVP
Key (a=9, b=25) -> Decrypted Text: CVNCZPCZNANAUNMPQQALZSM
Key (a=11, b=0) -> Decrypted Text: LKULSYLSUHUHVUFYNNHQSRF
Key (a=11, b=1) -> Decrypted Text: SRBSZFSZBOBOCBMFUUOXZYM
Key (a=11, b=2) -> Decrypted Text: ZYIZGMZGIVIVJITMBBVEGFT
Key (a=11, b=3) -> Decrypted Text: GFPGNTGNPCPCQPATIICLNMA
Key (a=11, b=4) -> Decrypted Text: NMWNUANUWJWJXWHAPPJSUTH
Key (a=11, b=5) -> Decrypted Text: UTDUBHUBDQDQEDOHWWQZBAO
Key (a=11, b=6) -> Decrypted Text: BAKBIOBIKXKXLKVODDXGIHV
Key (a=11, b=7) -> Decrypted Text: IHRIPVIPRERESRCVKKENPOC
Key (a=11, b=8) -> Decrypted Text: POYPWCPWYLYLZYJCRRLUWVJ
Key (a=11, b=9) -> Decrypted Text: WVFWDJWDFSFSGFQJYYSBDCQ
Key (a=11, b=10) -> Decrypted Text: DCMDKQDKMZMZNMXQFFZIKJX
Key (a=11, b=11) -> Decrypted Text: KJTKRXKRTGTGUTEXMMGPRQE
Key (a=11, b=12) -> Decrypted Text: RQARYERYANANBALETTNWYXL
Key (a=11, b=13) -> Decrypted Text: YXHYFLYFHUHUIHSLAAUDFES
Key (a=11, b=14) -> Decrypted Text: FEOFMSFMOBOBPOZSHHBKMLZ
Key (a=11, b=15) -> Decrypted Text: MLVMTZMTVIVIWVGZOOIRTSG
Key (a=11, b=16) -> Decrypted Text: TSCTAGTACPCPDCNGVVPYAZN
Key (a=11, b=17) -> Decrypted Text: AZJAHNAHJWJWKJUNCCWFHGU
Key (a=11, b=18) -> Decrypted Text: HGQHOUHOQDQDRQBUJJDMONB
Key (a=11, b=19) -> Decrypted Text: ONXOVBOVXKXKYXIBQQKTVUI
Key (a=11, b=20) -> Decrypted Text: VUEVCIVCERERFEPIXXRACBP
Key (a=11, b=21) -> Decrypted Text: CBLCJPCJLYLYMLWPEEYHJIW
Key (a=11, b=22) -> Decrypted Text: JISJQWJQSFSFTSDWLLFOQPD
Key (a=11, b=23) -> Decrypted Text: QPZQXDQXZMZMAZKDSSMVXWK
Key (a=11, b=24) -> Decrypted Text: XWGXEKXEGTGTHGRKZZTCEDR
Key (a=11, b=25) -> Decrypted Text: EDNELRELNANAONYRGGAJLKY
Key (a=15, b=0) -> Decrypted Text: PQGPICPIGTGTFGVCNNTKIJV
Key (a=15, b=1) -> Decrypted Text: IJZIBVIBZMZMYZOVGGMDBCO
Key (a=15, b=2) -> Decrypted Text: BCSBUOBUSFSFRSHOZZFWUVH
Key (a=15, b=3) -> Decrypted Text: UVLUNHUNLYLYKLAHSSYPNOA
Key (a=15, b=4) -> Decrypted Text: NOENGANGERERDETALLRIGHT
Key (a=15, b=5) -> Decrypted Text: GHXGZTGZXKXKWXMTEEKBZAM
Key (a=15, b=6) -> Decrypted Text: ZAQZSMZSQDQDPQFMXXDUSTF
Key (a=15, b=7) -> Decrypted Text: STJSLFSLJWJWIJYFQQWNLMY
Key (a=15, b=8) -> Decrypted Text: LMCLEYLECPCPBCRYJJPGEFR
Key (a=15, b=9) -> Decrypted Text: EFVEXREXVIVIUVKRCCIZXYK
Key (a=15, b=10) -> Decrypted Text: XYOXQKXQOBOBNODKVVBSQRD
Key (a=15, b=11) -> Decrypted Text: QRHQJDQJHUHUGHWDOOULJKW
Key (a=15, b=12) -> Decrypted Text: JKAJCWJCANANZAPWHHNECDP
Key (a=15, b=13) -> Decrypted Text: CDTCVPCVTGTGSTIPAAGXVWI
Key (a=15, b=14) -> Decrypted Text: VWMVOIVOMZMZLMBITTZQOPB
Key (a=15, b=15) -> Decrypted Text: OPFOHBOHFSFSEFUBMMSJHIU
Key (a=15, b=16) -> Decrypted Text: HIYHAUHAYLYLXYNUFFLCABN
Key (a=15, b=17) -> Decrypted Text: ABRATNATREREQRGNYYEVTUG
Key (a=15, b=18) -> Decrypted Text: TUKTMGTMKXKXJKZGRRXOMNZ
Key (a=15, b=19) -> Decrypted Text: MNDMFZMFDQDQCDSZKKQHFGS
Key (a=15, b=20) -> Decrypted Text: FGWFYSFYWJWJVWLSDDJAYZL
Key (a=15, b=21) -> Decrypted Text: YZPYRLYRPCPCOPELWWCTRSE
Key (a=15, b=22) -> Decrypted Text: RSIRKERKIVIVHIXEPPVMKLX
Key (a=15, b=23) -> Decrypted Text: KLBKDXKDBOBOABQXIIOFDEQ
Key (a=15, b=24) -> Decrypted Text: DEUDWQDWUHUHTUJQBBHYWXJ
Key (a=15, b=25) -> Decrypted Text: WXNWPJWPNANAMNCJUUARPQC
Key (a=17, b=0) -> Decrypted Text: BIQBEOBEQDQDJQRONNDSELR
Key (a=17, b=1) -> Decrypted Text: ELTEHREHTGTGMTURQQGVHOU
Key (a=17, b=2) -> Decrypted Text: HOWHKUHKWJWJPWXUTTJYKRX
Key (a=17, b=3) -> Decrypted Text: KRZKNXKNZMZMSZAXWWMBNUA
Key (a=17, b=4) -> Decrypted Text: NUCNQANQCPCPVCDAZZPEQXD
Key (a=17, b=5) -> Decrypted Text: QXFQTDQTFSFSYFGDCCSHTAG
Key (a=17, b=6) -> Decrypted Text: TAITWGTWIVIVBIJGFFVKWDJ
Key (a=17, b=7) -> Decrypted Text: WDLWZJWZLYLYELMJIIYNZGM
Key (a=17, b=8) -> Decrypted Text: ZGOZCMZCOBOBHOPMLLBQCJP
Key (a=17, b=9) -> Decrypted Text: CJRCFPCFREREKRSPOOETFMS
Key (a=17, b=10) -> Decrypted Text: FMUFISFIUHUHNUVSRRHWIPV
Key (a=17, b=11) -> Decrypted Text: IPXILVILXKXKQXYVUUKZLSY
Key (a=17, b=12) -> Decrypted Text: LSALOYLOANANTABYXXNCOVB
Key (a=17, b=13) -> Decrypted Text: OVDORBORDQDQWDEBAAQFRYE
Key (a=17, b=14) -> Decrypted Text: RYGRUERUGTGTZGHEDDTIUBH
Key (a=17, b=15) -> Decrypted Text: UBJUXHUXJWJWCJKHGGWLXEK
Key (a=17, b=16) -> Decrypted Text: XEMXAKXAMZMZFMNKJJZOAHN
Key (a=17, b=17) -> Decrypted Text: AHPADNADPCPCIPQNMMCRDKQ
Key (a=17, b=18) -> Decrypted Text: DKSDGQDGSFSFLSTQPPFUGNT
Key (a=17, b=19) -> Decrypted Text: GNVGJTGJVIVIOVWTSSIXJQW
Key (a=17, b=20) -> Decrypted Text: JQYJMWJMYLYLRYZWVVLAMTZ
Key (a=17, b=21) -> Decrypted Text: MTBMPZMPBOBOUBCZYYODPWC
Key (a=17, b=22) -> Decrypted Text: PWEPSCPSERERXEFCBBRGSZF
Key (a=17, b=23) -> Decrypted Text: SZHSVFSVHUHUAHIFEEUJVCI
Key (a=17, b=24) -> Decrypted Text: VCKVYIVYKXKXDKLIHHXMYFL
Key (a=17, b=25) -> Decrypted Text: YFNYBLYBNANAGNOLKKAPBIO
Key (a=19, b=0) -> Decrypted Text: FOCFUSFUCPCPTCHSNNPMUDH
Key (a=19, b=1) -> Decrypted Text: UDRUJHUJREREIRWHCCEBJSW
Key (a=19, b=2) -> Decrypted Text: JSGJYWJYGTGTXGLWRRTQYHL
Key (a=19, b=3) -> Decrypted Text: YHVYNLYNVIVIMVALGGIFNWA
Key (a=19, b=4) -> Decrypted Text: NWKNCANCKXKXBKPAVVXUCLP
Key (a=19, b=5) -> Decrypted Text: CLZCRPCRZMZMQZEPKKMJRAE
Key (a=19, b=6) -> Decrypted Text: RAORGERGOBOBFOTEZZBYGPT
Key (a=19, b=7) -> Decrypted Text: GPDGVTGVDQDQUDITOOQNVEI
Key (a=19, b=8) -> Decrypted Text: VESVKIVKSFSFJSXIDDFCKTX
Key (a=19, b=9) -> Decrypted Text: KTHKZXKZHUHUYHMXSSURZIM
Key (a=19, b=10) -> Decrypted Text: ZIWZOMZOWJWJNWBMHHJGOXB
Key (a=19, b=11) -> Decrypted Text: OXLODBODLYLYCLQBWWYVDMQ
Key (a=19, b=12) -> Decrypted Text: DMADSQDSANANRAFQLLNKSBF
Key (a=19, b=13) -> Decrypted Text: SBPSHFSHPCPCGPUFAACZHQU
Key (a=19, b=14) -> Decrypted Text: HQEHWUHWERERVEJUPPROWFJ
Key (a=19, b=15) -> Decrypted Text: WFTWLJWLTGTGKTYJEEGDLUY
Key (a=19, b=16) -> Decrypted Text: LUILAYLAIVIVZINYTTVSAJN
Key (a=19, b=17) -> Decrypted Text: AJXAPNAPXKXKOXCNIIKHPYC
Key (a=19, b=18) -> Decrypted Text: PYMPECPEMZMZDMRCXXZWENR
Key (a=19, b=19) -> Decrypted Text: ENBETRETBOBOSBGRMMOLTCG
Key (a=19, b=20) -> Decrypted Text: TCQTIGTIQDQDHQVGBBDAIRV
Key (a=19, b=21) -> Decrypted Text: IRFIXVIXFSFSWFKVQQSPXGK
Key (a=19, b=22) -> Decrypted Text: XGUXMKXMUHUHLUZKFFHEMVZ
Key (a=19, b=23) -> Decrypted Text: MVJMBZMBJWJWAJOZUUWTBKO
Key (a=19, b=24) -> Decrypted Text: BKYBQOBQYLYLPYDOJJLIQZD
Key (a=19, b=25) -> Decrypted Text: QZNQFDQFNANAENSDYYAXFOS
Key (a=21, b=0) -> Decrypted Text: HEIHCUHCIVIVLIPUNNVWCZP
Key (a=21, b=1) -> Decrypted Text: CZDCXPCXDQDQGDKPIIQRXUK
Key (a=21, b=2) -> Decrypted Text: XUYXSKXSYLYLBYFKDDLMSPF
Key (a=21, b=3) -> Decrypted Text: SPTSNFSNTGTGWTAFYYGHNKA
Key (a=21, b=4) -> Decrypted Text: NKONIANIOBOBROVATTBCIFV
Key (a=21, b=5) -> Decrypted Text: IFJIDVIDJWJWMJQVOOWXDAQ
Key (a=21, b=6) -> Decrypted Text: DAEDYQDYERERHELQJJRSYVL
Key (a=21, b=7) -> Decrypted Text: YVZYTLYTZMZMCZGLEEMNTQG
Key (a=21, b=8) -> Decrypted Text: TQUTOGTOUHUHXUBGZZHIOLB
Key (a=21, b=9) -> Decrypted Text: OLPOJBOJPCPCSPWBUUCDJGW
Key (a=21, b=10) -> Decrypted Text: JGKJEWJEKXKXNKRWPPXYEBR
Key (a=21, b=11) -> Decrypted Text: EBFEZREZFSFSIFMRKKSTZWM
Key (a=21, b=12) -> Decrypted Text: ZWAZUMZUANANDAHMFFNOURH
Key (a=21, b=13) -> Decrypted Text: URVUPHUPVIVIYVCHAAIJPMC
Key (a=21, b=14) -> Decrypted Text: PMQPKCPKQDQDTQXCVVDEKHX
Key (a=21, b=15) -> Decrypted Text: KHLKFXKFLYLYOLSXQQYZFCS
Key (a=21, b=16) -> Decrypted Text: FCGFASFAGTGTJGNSLLTUAXN
Key (a=21, b=17) -> Decrypted Text: AXBAVNAVBOBOEBINGGOPVSI
Key (a=21, b=18) -> Decrypted Text: VSWVQIVQWJWJZWDIBBJKQND
Key (a=21, b=19) -> Decrypted Text: QNRQLDQLREREURYDWWEFLIY
Key (a=21, b=20) -> Decrypted Text: LIMLGYLGMZMZPMTYRRZAGDT
Key (a=21, b=21) -> Decrypted Text: GDHGBTGBHUHUKHOTMMUVBYO
Key (a=21, b=22) -> Decrypted Text: BYCBWOBWCPCPFCJOHHPQWTJ
Key (a=21, b=23) -> Decrypted Text: WTXWRJWRXKXKAXEJCCKLROE
Key (a=21, b=24) -> Decrypted Text: ROSRMERMSFSFVSZEXXFGMJZ
Key (a=21, b=25) -> Decrypted Text: MJNMHZMHNANAQNUZSSABHEU
Key (a=23, b=0) -> Decrypted Text: DYWDMQDMWJWJBWZQNNJCMHZ
Key (a=23, b=1) -> Decrypted Text: MHFMVZMVFSFSKFIZWWSLVQI
Key (a=23, b=2) -> Decrypted Text: VQOVEIVEOBOBTORIFFBUEZR
Key (a=23, b=3) -> Decrypted Text: EZXENRENXKXKCXAROOKDNIA
Key (a=23, b=4) -> Decrypted Text: NIGNWANWGTGTLGJAXXTMWRJ
Key (a=23, b=5) -> Decrypted Text: WRPWFJWFPCPCUPSJGGCVFAS
Key (a=23, b=6) -> Decrypted Text: FAYFOSFOYLYLDYBSPPLEOJB
Key (a=23, b=7) -> Decrypted Text: OJHOXBOXHUHUMHKBYYUNXSK
Key (a=23, b=8) -> Decrypted Text: XSQXGKXGQDQDVQTKHHDWGBT
Key (a=23, b=9) -> Decrypted Text: GBZGPTGPZMZMEZCTQQMFPKC
Key (a=23, b=10) -> Decrypted Text: PKIPYCPYIVIVNILCZZVOYTL
Key (a=23, b=11) -> Decrypted Text: YTRYHLYHREREWRULIIEXHCU
Key (a=23, b=12) -> Decrypted Text: HCAHQUHQANANFADURRNGQLD
Key (a=23, b=13) -> Decrypted Text: QLJQZDQZJWJWOJMDAAWPZUM
Key (a=23, b=14) -> Decrypted Text: ZUSZIMZISFSFXSVMJJFYIDV
Key (a=23, b=15) -> Decrypted Text: IDBIRVIRBOBOGBEVSSOHRME
Key (a=23, b=16) -> Decrypted Text: RMKRAERAKXKXPKNEBBXQAVN
Key (a=23, b=17) -> Decrypted Text: AVTAJNAJTGTGYTWNKKGZJEW
Key (a=23, b=18) -> Decrypted Text: JECJSWJSCPCPHCFWTTPISNF
Key (a=23, b=19) -> Decrypted Text: SNLSBFSBLYLYQLOFCCYRBWO
Key (a=23, b=20) -> Decrypted Text: BWUBKOBKUHUHZUXOLLHAKFX
Key (a=23, b=21) -> Decrypted Text: KFDKTXKTDQDQIDGXUUQJTOG
Key (a=23, b=22) -> Decrypted Text: TOMTCGTCMZMZRMPGDDZSCXP
Key (a=23, b=23) -> Decrypted Text: CXVCLPCLVIVIAVYPMMIBLGY
Key (a=23, b=24) -> Decrypted Text: LGELUYLUERERJEHYVVRKUPH
Key (a=23, b=25) -> Decrypted Text: UPNUDHUDNANASNQHEEATDYQ
Key (a=25, b=0) -> Decrypted Text: JUOJKWJKOBOBDOXWNNBGKVX
Key (a=25, b=1) -> Decrypted Text: KVPKLXKLPCPCEPYXOOCHLWY
Key (a=25, b=2) -> Decrypted Text: LWQLMYLMQDQDFQZYPPDIMXZ
Key (a=25, b=3) -> Decrypted Text: MXRMNZMNREREGRAZQQEJNYA
Key (a=25, b=4) -> Decrypted Text: NYSNOANOSFSFHSBARRFKOZB
Key (a=25, b=5) -> Decrypted Text: OZTOPBOPTGTGITCBSSGLPAC
Key (a=25, b=6) -> Decrypted Text: PAUPQCPQUHUHJUDCTTHMQBD
Key (a=25, b=7) -> Decrypted Text: QBVQRDQRVIVIKVEDUUINRCE
Key (a=25, b=8) -> Decrypted Text: RCWRSERSWJWJLWFEVVJOSDF
Key (a=25, b=9) -> Decrypted Text: SDXSTFSTXKXKMXGFWWKPTEG
Key (a=25, b=10) -> Decrypted Text: TEYTUGTUYLYLNYHGXXLQUFH
Key (a=25, b=11) -> Decrypted Text: UFZUVHUVZMZMOZIHYYMRVGI
Key (a=25, b=12) -> Decrypted Text: VGAVWIVWANANPAJIZZNSWHJ
Key (a=25, b=13) -> Decrypted Text: WHBWXJWXBOBOQBKJAAOTXIK
Key (a=25, b=14) -> Decrypted Text: XICXYKXYCPCPRCLKBBPUYJL
Key (a=25, b=15) -> Decrypted Text: YJDYZLYZDQDQSDMLCCQVZKM
Key (a=25, b=16) -> Decrypted Text: ZKEZAMZAERERTENMDDRWALN
Key (a=25, b=17) -> Decrypted Text: ALFABNABFSFSUFONEESXBMO
Key (a=25, b=18) -> Decrypted Text: BMGBCOBCGTGTVGPOFFTYCNP
Key (a=25, b=19) -> Decrypted Text: CNHCDPCDHUHUWHQPGGUZDOQ
Key (a=25, b=20) -> Decrypted Text: DOIDEQDEIVIVXIRQHHVAEPR
Key (a=25, b=21) -> Decrypted Text: EPJEFREFJWJWYJSRIIWBFQS
Key (a=25, b=22) -> Decrypted Text: FQKFGSFGKXKXZKTSJJXCGRT
Key (a=25, b=23) -> Decrypted Text: GRLGHTGHLYLYALUTKKYDHSU
Key (a=25, b=24) -> Decrypted Text: HSMHIUHIMZMZBMVULLZEITV
Key (a=25, b=25) -> Decrypted Text: ITNIJVIJNANACNWVMMAFJUW
Key (a=1, b=0) -> Decrypted Text: RGMRQERQMZMZXMDENNZUQFD
Key (a=1, b=1) -> Decrypted Text: QFLQPDQPLYLYWLCDMMYTPEC
Key (a=1, b=2) -> Decrypted Text: PEKPOCPOKXKXVKBCLLXSODB
Key (a=1, b=3) -> Decrypted Text: ODJONBONJWJWUJABKKWRNCA
Key (a=1, b=4) -> Decrypted Text: NCINMANMIVIVTIZAJJVQMBZ
Key (a=1, b=5) -> Decrypted Text: MBHMLZMLHUHUSHYZIIUPLAY
Key (a=1, b=6) -> Decrypted Text: LAGLKYLKGTGTRGXYHHTOKZX
Key (a=1, b=7) -> Decrypted Text: KZFKJXKJFSFSQFWXGGSNJYW
Key (a=1, b=8) -> Decrypted Text: JYEJIWJIERERPEVWFFRMIXV
Key (a=1, b=9) -> Decrypted Text: IXDIHVIHDQDQODUVEEQLHWU
Key (a=1, b=10) -> Decrypted Text: HWCHGUHGCPCPNCTUDDPKGVT
Key (a=1, b=11) -> Decrypted Text: GVBGFTGFBOBOMBSTCCOJFUS
Key (a=1, b=12) -> Decrypted Text: FUAFESFEANANLARSBBNIETR
Key (a=1, b=13) -> Decrypted Text: ETZEDREDZMZMKZQRAAMHDSQ
Key (a=1, b=14) -> Decrypted Text: DSYDCQDCYLYLJYPQZZLGCRP
Key (a=1, b=15) -> Decrypted Text: CRXCBPCBXKXKIXOPYYKFBQO
Key (a=1, b=16) -> Decrypted Text: BQWBAOBAWJWJHWNOXXJEAPN
Key (a=1, b=17) -> Decrypted Text: APVAZNAZVIVIGVMNWWIDZOM
Key (a=1, b=18) -> Decrypted Text: ZOUZYMZYUHUHFULMVVHCYNL
Key (a=1, b=19) -> Decrypted Text: YNTYXLYXTGTGETKLUUGBXMK
Key (a=1, b=20) -> Decrypted Text: XMSXWKXWSFSFDSJKTTFAWLJ
Key (a=1, b=21) -> Decrypted Text: WLRWVJWVRERECRIJSSEZVKI
Key (a=1, b=22) -> Decrypted Text: VKQVUIVUQDQDBQHIRRDYUJH
Key (a=1, b=23) -> Decrypted Text: UJPUTHUTPCPCAPGHQQCXTIG
Key (a=1, b=24) -> Decrypted Text: TIOTSGTSOBOBZOFGPPBWSHF
Key (a=1, b=25) -> Decrypted Text: SHNSRFSRNANAYNEFOOAVRGE
Key (a=3, b=0) -> Decrypted Text: XCEXOKXOERERZEBKNNRYOTB
Key (a=3, b=1) -> Decrypted Text: OTVOFBOFVIVIQVSBEEIPFKS
Key (a=3, b=2) -> Decrypted Text: FKMFWSFWMZMZHMJSVVZGWBJ
Key (a=3, b=3) -> Decrypted Text: WBDWNJWNDQDQYDAJMMQXNSA
Key (a=3, b=4) -> Decrypted Text: NSUNEANEUHUHPURADDHOEJR
Key (a=3, b=5) -> Decrypted Text: EJLEVREVLYLYGLIRUUYFVAI
Key (a=3, b=6) -> Decrypted Text: VACVMIVMCPCPXCZILLPWMRZ
Key (a=3, b=7) -> Decrypted Text: MRTMDZMDTGTGOTQZCCGNDIQ
Key (a=3, b=8) -> Decrypted Text: DIKDUQDUKXKXFKHQTTXEUZH
Key (a=3, b=9) -> Decrypted Text: UZBULHULBOBOWBYHKKOVLQY
Key (a=3, b=10) -> Decrypted Text: LQSLCYLCSFSFNSPYBBFMCHP
Key (a=3, b=11) -> Decrypted Text: CHJCTPCTJWJWEJGPSSWDTYG
Key (a=3, b=12) -> Decrypted Text: TYATKGTKANANVAXGJJNUKPX
Key (a=3, b=13) -> Decrypted Text: KPRKBXKBREREMROXAAELBGO
Key (a=3, b=14) -> Decrypted Text: BGIBSOBSIVIVDIFORRVCSXF
Key (a=3, b=15) -> Decrypted Text: SXZSJFSJZMZMUZWFIIMTJOW
Key (a=3, b=16) -> Decrypted Text: JOQJAWJAQDQDLQNWZZDKAFN
Key (a=3, b=17) -> Decrypted Text: AFHARNARHUHUCHENQQUBRWE
Key (a=3, b=18) -> Decrypted Text: RWYRIERIYLYLTYVEHHLSINV
Key (a=3, b=19) -> Decrypted Text: INPIZVIZPCPCKPMVYYCJZEM
Key (a=3, b=20) -> Decrypted Text: ZEGZQMZQGTGTBGDMPPTAQVD
Key (a=3, b=21) -> Decrypted Text: QVXQHDQHXKXKSXUDGGKRHMU
Key (a=3, b=22) -> Decrypted Text: HMOHYUHYOBOBJOLUXXBIYDL
Key (a=3, b=23) -> Decrypted Text: YDFYPLYPFSFSAFCLOOSZPUC
Key (a=3, b=24) -> Decrypted Text: PUWPGCPGWJWJRWTCFFJQGLT
Key (a=3, b=25) -> Decrypted Text: GLNGXTGXNANAINKTWWAHXCK
Key (a=5, b=0) -> Decrypted Text: TWSTYGTYSFSFPSLGNNFEYBL
Key (a=5, b=1) -> Decrypted Text: YBXYDLYDXKXKUXQLSSKJDGQ
Key (a=5, b=2) -> Decrypted Text: DGCDIQDICPCPZCVQXXPOILV
Key (a=5, b=3) -> Decrypted Text: ILHINVINHUHUEHAVCCUTNQA
Key (a=5, b=4) -> Decrypted Text: NQMNSANSMZMZJMFAHHZYSVF
Key (a=5, b=5) -> Decrypted Text: SVRSXFSXREREORKFMMEDXAK
Key (a=5, b=6) -> Decrypted Text: XAWXCKXCWJWJTWPKRRJICFP
Key (a=5, b=7) -> Decrypted Text: CFBCHPCHBOBOYBUPWWONHKU
Key (a=5, b=8) -> Decrypted Text: HKGHMUHMGTGTDGZUBBTSMPZ
Key (a=5, b=9) -> Decrypted Text: MPLMRZMRLYLYILEZGGYXRUE
Key (a=5, b=10) -> Decrypted Text: RUQRWERWQDQDNQJELLDCWZJ
Key (a=5, b=11) -> Decrypted Text: WZVWBJWBVIVISVOJQQIHBEO
Key (a=5, b=12) -> Decrypted Text: BEABGOBGANANXATOVVNMGJT
Key (a=5, b=13) -> Decrypted Text: GJFGLTGLFSFSCFYTAASRLOY
Key (a=5, b=14) -> Decrypted Text: LOKLQYLQKXKXHKDYFFXWQTD
Key (a=5, b=15) -> Decrypted Text: QTPQVDQVPCPCMPIDKKCBVYI
Key (a=5, b=16) -> Decrypted Text: VYUVAIVAUHUHRUNIPPHGADN
Key (a=5, b=17) -> Decrypted Text: ADZAFNAFZMZMWZSNUUMLFIS
Key (a=5, b=18) -> Decrypted Text: FIEFKSFKERERBEXSZZRQKNX
Key (a=5, b=19) -> Decrypted Text: KNJKPXKPJWJWGJCXEEWVPSC
Key (a=5, b=20) -> Decrypted Text: PSOPUCPUOBOBLOHCJJBAUXH
Key (a=5, b=21) -> Decrypted Text: UXTUZHUZTGTGQTMHOOGFZCM
Key (a=5, b=22) -> Decrypted Text: ZCYZEMZEYLYLVYRMTTLKEHR
Key (a=5, b=23) -> Decrypted Text: EHDEJREJDQDQADWRYYQPJMW
Key (a=5, b=24) -> Decrypted Text: JMIJOWJOIVIVFIBWDDVUORB
Key (a=5, b=25) -> Decrypted Text: ORNOTBOTNANAKNGBIIAZTWG
Key (a=7, b=0) -> Decrypted Text: VMYVGIVGYLYLHYTINNLOGXT
Key (a=7, b=1) -> Decrypted Text: GXJGRTGRJWJWSJETYYWZRIE
Key (a=7, b=2) -> Decrypted Text: RIURCERCUHUHDUPEJJHKCTP
Key (a=7, b=3) -> Decrypted Text: CTFCNPCNFSFSOFAPUUSVNEA
Key (a=7, b=4) -> Decrypted Text: NEQNYANYQDQDZQLAFFDGYPL
Key (a=7, b=5) -> Decrypted Text: YPBYJLYJBOBOKBWLQQORJAW
Key (a=7, b=6) -> Decrypted Text: JAMJUWJUMZMZVMHWBBZCULH
Key (a=7, b=7) -> Decrypted Text: ULXUFHUFXKXKGXSHMMKNFWS
Key (a=7, b=8) -> Decrypted Text: FWIFQSFQIVIVRIDSXXVYQHD
Key (a=7, b=9) -> Decrypted Text: QHTQBDQBTGTGCTODIIGJBSO
Key (a=7, b=10) -> Decrypted Text: BSEBMOBMERERNEZOTTRUMDZ
Key (a=7, b=11) -> Decrypted Text: MDPMXZMXPCPCYPKZEECFXOK
Key (a=7, b=12) -> Decrypted Text: XOAXIKXIANANJAVKPPNQIZV
Key (a=7, b=13) -> Decrypted Text: IZLITVITLYLYULGVAAYBTKG
Key (a=7, b=14) -> Decrypted Text: TKWTEGTEWJWJFWRGLLJMEVR
Key (a=7, b=15) -> Decrypted Text: EVHEPREPHUHUQHCRWWUXPGC
Key (a=7, b=16) -> Decrypted Text: PGSPACPASFSFBSNCHHFIARN
Key (a=7, b=17) -> Decrypted Text: ARDALNALDQDQMDYNSSQTLCY
Key (a=7, b=18) -> Decrypted Text: LCOLWYLWOBOBXOJYDDBEWNJ
Key (a=7, b=19) -> Decrypted Text: WNZWHJWHZMZMIZUJOOMPHYU
Key (a=7, b=20) -> Decrypted Text: HYKHSUHSKXKXTKFUZZXASJF
Key (a=7, b=21) -> Decrypted Text: SJVSDFSDVIVIEVQFKKILDUQ
Key (a=7, b=22) -> Decrypted Text: DUGDOQDOGTGTPGBQVVTWOFB
Key (a=7, b=23) -> Decrypted Text: OFROZBOZREREARMBGGEHZQM
Key (a=7, b=24) -> Decrypted Text: ZQCZKMZKCPCPLCXMRRPSKBX
Key (a=7, b=25) -> Decrypted Text: KBNKVXKVNANAWNIXCCADVMI
Key (a=9, b=0) -> Decrypted Text: ZSKZWMZWKXKXRKJMNNXIWPJ
Key (a=9, b=1) -> Decrypted Text: WPHWTJWTHUHUOHGJKKUFTMG
Key (a=9, b=2) -> Decrypted Text: TMETQGTQERERLEDGHHRCQJD
Key (a=9, b=3) -> Decrypted Text: QJBQNDQNBOBOIBADEEOZNGA
Key (a=9, b=4) -> Decrypted Text: NGYNKANKYLYLFYXABBLWKDX
Key (a=9, b=5) -> Decrypted Text: KDVKHXKHVIVICVUXYYITHAU
Key (a=9, b=6) -> Decrypted Text: HASHEUHESFSFZSRUVVFQEXR
Key (a=9, b=7) -> Decrypted Text: EXPEBREBPCPCWPORSSCNBUO
Key (a=9, b=8) -> Decrypted Text: BUMBYOBYMZMZTMLOPPZKYRL
Key (a=9, b=9) -> Decrypted Text: YRJYVLYVJWJWQJILMMWHVOI
Key (a=9, b=10) -> Decrypted Text: VOGVSIVSGTGTNGFIJJTESLF
Key (a=9, b=11) -> Decrypted Text: SLDSPFSPDQDQKDCFGGQBPIC
Key (a=9, b=12) -> Decrypted Text: PIAPMCPMANANHAZCDDNYMFZ
Key (a=9, b=13) -> Decrypted Text: MFXMJZMJXKXKEXWZAAKVJCW
Key (a=9, b=14) -> Decrypted Text: JCUJGWJGUHUHBUTWXXHSGZT
Key (a=9, b=15) -> Decrypted Text: GZRGDTGDREREYRQTUUEPDWQ
Key (a=9, b=16) -> Decrypted Text: DWODAQDAOBOBVONQRRBMATN
Key (a=9, b=17) -> Decrypted Text: ATLAXNAXLYLYSLKNOOYJXQK
Key (a=9, b=18) -> Decrypted Text: XQIXUKXUIVIVPIHKLLVGUNH
Key (a=9, b=19) -> Decrypted Text: UNFURHURFSFSMFEHIISDRKE
Key (a=9, b=20) -> Decrypted Text: RKCROEROCPCPJCBEFFPAOHB
Key (a=9, b=21) -> Decrypted Text: OHZOLBOLZMZMGZYBCCMXLEY
Key (a=9, b=22) -> Decrypted Text: LEWLIYLIWJWJDWVYZZJUIBV
Key (a=9, b=23) -> Decrypted Text: IBTIFVIFTGTGATSVWWGRFYS
Key (a=9, b=24) -> Decrypted Text: FYQFCSFCQDQDXQPSTTDOCVP
Key (a=9, b=25) -> Decrypted Text: CVNCZPCZNANAUNMPQQALZSM
Key (a=11, b=0) -> Decrypted Text: LKULSYLSUHUHVUFYNNHQSRF
Key (a=11, b=1) -> Decrypted Text: SRBSZFSZBOBOCBMFUUOXZYM
Key (a=11, b=2) -> Decrypted Text: ZYIZGMZGIVIVJITMBBVEGFT
Key (a=11, b=3) -> Decrypted Text: GFPGNTGNPCPCQPATIICLNMA
Key (a=11, b=4) -> Decrypted Text: NMWNUANUWJWJXWHAPPJSUTH
Key (a=11, b=5) -> Decrypted Text: UTDUBHUBDQDQEDOHWWQZBAO
Key (a=11, b=6) -> Decrypted Text: BAKBIOBIKXKXLKVODDXGIHV
Key (a=11, b=7) -> Decrypted Text: IHRIPVIPRERESRCVKKENPOC
Key (a=11, b=8) -> Decrypted Text: POYPWCPWYLYLZYJCRRLUWVJ
Key (a=11, b=9) -> Decrypted Text: WVFWDJWDFSFSGFQJYYSBDCQ
Key (a=11, b=10) -> Decrypted Text: DCMDKQDKMZMZNMXQFFZIKJX
Key (a=11, b=11) -> Decrypted Text: KJTKRXKRTGTGUTEXMMGPRQE
Key (a=11, b=12) -> Decrypted Text: RQARYERYANANBALETTNWYXL
Key (a=11, b=13) -> Decrypted Text: YXHYFLYFHUHUIHSLAAUDFES
Key (a=11, b=14) -> Decrypted Text: FEOFMSFMOBOBPOZSHHBKMLZ
Key (a=11, b=15) -> Decrypted Text: MLVMTZMTVIVIWVGZOOIRTSG
Key (a=11, b=16) -> Decrypted Text: TSCTAGTACPCPDCNGVVPYAZN
Key (a=11, b=17) -> Decrypted Text: AZJAHNAHJWJWKJUNCCWFHGU
Key (a=11, b=18) -> Decrypted Text: HGQHOUHOQDQDRQBUJJDMONB
Key (a=11, b=19) -> Decrypted Text: ONXOVBOVXKXKYXIBQQKTVUI
Key (a=11, b=20) -> Decrypted Text: VUEVCIVCERERFEPIXXRACBP
Key (a=11, b=21) -> Decrypted Text: CBLCJPCJLYLYMLWPEEYHJIW
Key (a=11, b=22) -> Decrypted Text: JISJQWJQSFSFTSDWLLFOQPD
Key (a=11, b=23) -> Decrypted Text: QPZQXDQXZMZMAZKDSSMVXWK
Key (a=11, b=24) -> Decrypted Text: XWGXEKXEGTGTHGRKZZTCEDR
Key (a=11, b=25) -> Decrypted Text: EDNELRELNANAONYRGGAJLKY
Key (a=15, b=0) -> Decrypted Text: PQGPICPIGTGTFGVCNNTKIJV
Key (a=15, b=1) -> Decrypted Text: IJZIBVIBZMZMYZOVGGMDBCO
Key (a=15, b=2) -> Decrypted Text: BCSBUOBUSFSFRSHOZZFWUVH
Key (a=15, b=3) -> Decrypted Text: UVLUNHUNLYLYKLAHSSYPNOA
Key (a=15, b=4) -> Decrypted Text: NOENGANGERERDETALLRIGHT
Key (a=15, b=5) -> Decrypted Text: GHXGZTGZXKXKWXMTEEKBZAM
Key (a=15, b=6) -> Decrypted Text: ZAQZSMZSQDQDPQFMXXDUSTF
Key (a=15, b=7) -> Decrypted Text: STJSLFSLJWJWIJYFQQWNLMY
Key (a=15, b=8) -> Decrypted Text: LMCLEYLECPCPBCRYJJPGEFR
Key (a=15, b=9) -> Decrypted Text: EFVEXREXVIVIUVKRCCIZXYK
Key (a=15, b=10) -> Decrypted Text: XYOXQKXQOBOBNODKVVBSQRD
Key (a=15, b=11) -> Decrypted Text: QRHQJDQJHUHUGHWDOOULJKW
Key (a=15, b=12) -> Decrypted Text: JKAJCWJCANANZAPWHHNECDP
Key (a=15, b=13) -> Decrypted Text: CDTCVPCVTGTGSTIPAAGXVWI
Key (a=15, b=14) -> Decrypted Text: VWMVOIVOMZMZLMBITTZQOPB
Key (a=15, b=15) -> Decrypted Text: OPFOHBOHFSFSEFUBMMSJHIU
Key (a=15, b=16) -> Decrypted Text: HIYHAUHAYLYLXYNUFFLCABN
Key (a=15, b=17) -> Decrypted Text: ABRATNATREREQRGNYYEVTUG
Key (a=15, b=18) -> Decrypted Text: TUKTMGTMKXKXJKZGRRXOMNZ
Key (a=15, b=19) -> Decrypted Text: MNDMFZMFDQDQCDSZKKQHFGS
Key (a=15, b=20) -> Decrypted Text: FGWFYSFYWJWJVWLSDDJAYZL
Key (a=15, b=21) -> Decrypted Text: YZPYRLYRPCPCOPELWWCTRSE
Key (a=15, b=22) -> Decrypted Text: RSIRKERKIVIVHIXEPPVMKLX
Key (a=15, b=23) -> Decrypted Text: KLBKDXKDBOBOABQXIIOFDEQ
Key (a=15, b=24) -> Decrypted Text: DEUDWQDWUHUHTUJQBBHYWXJ
Key (a=15, b=25) -> Decrypted Text: WXNWPJWPNANAMNCJUUARPQC
Key (a=17, b=0) -> Decrypted Text: BIQBEOBEQDQDJQRONNDSELR
Key (a=17, b=1) -> Decrypted Text: ELTEHREHTGTGMTURQQGVHOU
Key (a=17, b=2) -> Decrypted Text: HOWHKUHKWJWJPWXUTTJYKRX
Key (a=17, b=3) -> Decrypted Text: KRZKNXKNZMZMSZAXWWMBNUA
Key (a=17, b=4) -> Decrypted Text: NUCNQANQCPCPVCDAZZPEQXD
Key (a=17, b=5) -> Decrypted Text: QXFQTDQTFSFSYFGDCCSHTAG
Key (a=17, b=6) -> Decrypted Text: TAITWGTWIVIVBIJGFFVKWDJ
Key (a=17, b=7) -> Decrypted Text: WDLWZJWZLYLYELMJIIYNZGM
Key (a=17, b=8) -> Decrypted Text: ZGOZCMZCOBOBHOPMLLBQCJP
Key (a=17, b=9) -> Decrypted Text: CJRCFPCFREREKRSPOOETFMS
Key (a=17, b=10) -> Decrypted Text: FMUFISFIUHUHNUVSRRHWIPV
Key (a=17, b=11) -> Decrypted Text: IPXILVILXKXKQXYVUUKZLSY
Key (a=17, b=12) -> Decrypted Text: LSALOYLOANANTABYXXNCOVB
Key (a=17, b=13) -> Decrypted Text: OVDORBORDQDQWDEBAAQFRYE
Key (a=17, b=14) -> Decrypted Text: RYGRUERUGTGTZGHEDDTIUBH
Key (a=17, b=15) -> Decrypted Text: UBJUXHUXJWJWCJKHGGWLXEK
Key (a=17, b=16) -> Decrypted Text: XEMXAKXAMZMZFMNKJJZOAHN
Key (a=17, b=17) -> Decrypted Text: AHPADNADPCPCIPQNMMCRDKQ
Key (a=17, b=18) -> Decrypted Text: DKSDGQDGSFSFLSTQPPFUGNT
Key (a=17, b=19) -> Decrypted Text: GNVGJTGJVIVIOVWTSSIXJQW
Key (a=17, b=20) -> Decrypted Text: JQYJMWJMYLYLRYZWVVLAMTZ
Key (a=17, b=21) -> Decrypted Text: MTBMPZMPBOBOUBCZYYODPWC
Key (a=17, b=22) -> Decrypted Text: PWEPSCPSERERXEFCBBRGSZF
Key (a=17, b=23) -> Decrypted Text: SZHSVFSVHUHUAHIFEEUJVCI
Key (a=17, b=24) -> Decrypted Text: VCKVYIVYKXKXDKLIHHXMYFL
Key (a=17, b=25) -> Decrypted Text: YFNYBLYBNANAGNOLKKAPBIO
Key (a=19, b=0) -> Decrypted Text: FOCFUSFUCPCPTCHSNNPMUDH
Key (a=19, b=1) -> Decrypted Text: UDRUJHUJREREIRWHCCEBJSW
Key (a=19, b=2) -> Decrypted Text: JSGJYWJYGTGTXGLWRRTQYHL
Key (a=19, b=3) -> Decrypted Text: YHVYNLYNVIVIMVALGGIFNWA
Key (a=19, b=4) -> Decrypted Text: NWKNCANCKXKXBKPAVVXUCLP
Key (a=19, b=5) -> Decrypted Text: CLZCRPCRZMZMQZEPKKMJRAE
Key (a=19, b=6) -> Decrypted Text: RAORGERGOBOBFOTEZZBYGPT
Key (a=19, b=7) -> Decrypted Text: GPDGVTGVDQDQUDITOOQNVEI
Key (a=19, b=8) -> Decrypted Text: VESVKIVKSFSFJSXIDDFCKTX
Key (a=19, b=9) -> Decrypted Text: KTHKZXKZHUHUYHMXSSURZIM
Key (a=19, b=10) -> Decrypted Text: ZIWZOMZOWJWJNWBMHHJGOXB
Key (a=19, b=11) -> Decrypted Text: OXLODBODLYLYCLQBWWYVDMQ
Key (a=19, b=12) -> Decrypted Text: DMADSQDSANANRAFQLLNKSBF
Key (a=19, b=13) -> Decrypted Text: SBPSHFSHPCPCGPUFAACZHQU
Key (a=19, b=14) -> Decrypted Text: HQEHWUHWERERVEJUPPROWFJ
Key (a=19, b=15) -> Decrypted Text: WFTWLJWLTGTGKTYJEEGDLUY
Key (a=19, b=16) -> Decrypted Text: LUILAYLAIVIVZINYTTVSAJN
Key (a=19, b=17) -> Decrypted Text: AJXAPNAPXKXKOXCNIIKHPYC
Key (a=19, b=18) -> Decrypted Text: PYMPECPEMZMZDMRCXXZWENR
Key (a=19, b=19) -> Decrypted Text: ENBETRETBOBOSBGRMMOLTCG
Key (a=19, b=20) -> Decrypted Text: TCQTIGTIQDQDHQVGBBDAIRV
Key (a=19, b=21) -> Decrypted Text: IRFIXVIXFSFSWFKVQQSPXGK
Key (a=19, b=22) -> Decrypted Text: XGUXMKXMUHUHLUZKFFHEMVZ
Key (a=19, b=23) -> Decrypted Text: MVJMBZMBJWJWAJOZUUWTBKO
Key (a=19, b=24) -> Decrypted Text: BKYBQOBQYLYLPYDOJJLIQZD
Key (a=19, b=25) -> Decrypted Text: QZNQFDQFNANAENSDYYAXFOS
Key (a=21, b=0) -> Decrypted Text: HEIHCUHCIVIVLIPUNNVWCZP
Key (a=21, b=1) -> Decrypted Text: CZDCXPCXDQDQGDKPIIQRXUK
Key (a=21, b=2) -> Decrypted Text: XUYXSKXSYLYLBYFKDDLMSPF
Key (a=21, b=3) -> Decrypted Text: SPTSNFSNTGTGWTAFYYGHNKA
Key (a=21, b=4) -> Decrypted Text: NKONIANIOBOBROVATTBCIFV
Key (a=21, b=5) -> Decrypted Text: IFJIDVIDJWJWMJQVOOWXDAQ
Key (a=21, b=6) -> Decrypted Text: DAEDYQDYERERHELQJJRSYVL
Key (a=21, b=7) -> Decrypted Text: YVZYTLYTZMZMCZGLEEMNTQG
Key (a=21, b=8) -> Decrypted Text: TQUTOGTOUHUHXUBGZZHIOLB
Key (a=21, b=9) -> Decrypted Text: OLPOJBOJPCPCSPWBUUCDJGW
Key (a=21, b=10) -> Decrypted Text: JGKJEWJEKXKXNKRWPPXYEBR
Key (a=21, b=11) -> Decrypted Text: EBFEZREZFSFSIFMRKKSTZWM
Key (a=21, b=12) -> Decrypted Text: ZWAZUMZUANANDAHMFFNOURH
Key (a=21, b=13) -> Decrypted Text: URVUPHUPVIVIYVCHAAIJPMC
Key (a=21, b=14) -> Decrypted Text: PMQPKCPKQDQDTQXCVVDEKHX
Key (a=21, b=15) -> Decrypted Text: KHLKFXKFLYLYOLSXQQYZFCS
Key (a=21, b=16) -> Decrypted Text: FCGFASFAGTGTJGNSLLTUAXN
Key (a=21, b=17) -> Decrypted Text: AXBAVNAVBOBOEBINGGOPVSI
Key (a=21, b=18) -> Decrypted Text: VSWVQIVQWJWJZWDIBBJKQND
Key (a=21, b=19) -> Decrypted Text: QNRQLDQLREREURYDWWEFLIY
Key (a=21, b=20) -> Decrypted Text: LIMLGYLGMZMZPMTYRRZAGDT
Key (a=21, b=21) -> Decrypted Text: GDHGBTGBHUHUKHOTMMUVBYO
Key (a=21, b=22) -> Decrypted Text: BYCBWOBWCPCPFCJOHHPQWTJ
Key (a=21, b=23) -> Decrypted Text: WTXWRJWRXKXKAXEJCCKLROE
Key (a=21, b=24) -> Decrypted Text: ROSRMERMSFSFVSZEXXFGMJZ
Key (a=21, b=25) -> Decrypted Text: MJNMHZMHNANAQNUZSSABHEU
Key (a=23, b=0) -> Decrypted Text: DYWDMQDMWJWJBWZQNNJCMHZ
Key (a=23, b=1) -> Decrypted Text: MHFMVZMVFSFSKFIZWWSLVQI
Key (a=23, b=2) -> Decrypted Text: VQOVEIVEOBOBTORIFFBUEZR
Key (a=23, b=3) -> Decrypted Text: EZXENRENXKXKCXAROOKDNIA
Key (a=23, b=4) -> Decrypted Text: NIGNWANWGTGTLGJAXXTMWRJ
Key (a=23, b=5) -> Decrypted Text: WRPWFJWFPCPCUPSJGGCVFAS
Key (a=23, b=6) -> Decrypted Text: FAYFOSFOYLYLDYBSPPLEOJB
Key (a=23, b=7) -> Decrypted Text: OJHOXBOXHUHUMHKBYYUNXSK
Key (a=23, b=8) -> Decrypted Text: XSQXGKXGQDQDVQTKHHDWGBT
Key (a=23, b=9) -> Decrypted Text: GBZGPTGPZMZMEZCTQQMFPKC
Key (a=23, b=10) -> Decrypted Text: PKIPYCPYIVIVNILCZZVOYTL
Key (a=23, b=11) -> Decrypted Text: YTRYHLYHREREWRULIIEXHCU
Key (a=23, b=12) -> Decrypted Text: HCAHQUHQANANFADURRNGQLD
Key (a=23, b=13) -> Decrypted Text: QLJQZDQZJWJWOJMDAAWPZUM
Key (a=23, b=14) -> Decrypted Text: ZUSZIMZISFSFXSVMJJFYIDV
Key (a=23, b=15) -> Decrypted Text: IDBIRVIRBOBOGBEVSSOHRME
Key (a=23, b=16) -> Decrypted Text: RMKRAERAKXKXPKNEBBXQAVN
Key (a=23, b=17) -> Decrypted Text: AVTAJNAJTGTGYTWNKKGZJEW
Key (a=23, b=18) -> Decrypted Text: JECJSWJSCPCPHCFWTTPISNF
Key (a=23, b=19) -> Decrypted Text: SNLSBFSBLYLYQLOFCCYRBWO
Key (a=23, b=20) -> Decrypted Text: BWUBKOBKUHUHZUXOLLHAKFX
Key (a=23, b=21) -> Decrypted Text: KFDKTXKTDQDQIDGXUUQJTOG
Key (a=23, b=22) -> Decrypted Text: TOMTCGTCMZMZRMPGDDZSCXP
Key (a=23, b=23) -> Decrypted Text: CXVCLPCLVIVIAVYPMMIBLGY
Key (a=23, b=24) -> Decrypted Text: LGELUYLUERERJEHYVVRKUPH
Key (a=23, b=25) -> Decrypted Text: UPNUDHUDNANASNQHEEATDYQ
Key (a=25, b=0) -> Decrypted Text: JUOJKWJKOBOBDOXWNNBGKVX
Key (a=25, b=1) -> Decrypted Text: KVPKLXKLPCPCEPYXOOCHLWY
Key (a=25, b=2) -> Decrypted Text: LWQLMYLMQDQDFQZYPPDIMXZ
Key (a=25, b=3) -> Decrypted Text: MXRMNZMNREREGRAZQQEJNYA
Key (a=25, b=4) -> Decrypted Text: NYSNOANOSFSFHSBARRFKOZB
Key (a=25, b=5) -> Decrypted Text: OZTOPBOPTGTGITCBSSGLPAC
Key (a=25, b=6) -> Decrypted Text: PAUPQCPQUHUHJUDCTTHMQBD
Key (a=25, b=7) -> Decrypted Text: QBVQRDQRVIVIKVEDUUINRCE
Key (a=25, b=8) -> Decrypted Text: RCWRSERSWJWJLWFEVVJOSDF
Key (a=25, b=9) -> Decrypted Text: SDXSTFSTXKXKMXGFWWKPTEG
Key (a=25, b=10) -> Decrypted Text: TEYTUGTUYLYLNYHGXXLQUFH
Key (a=25, b=11) -> Decrypted Text: UFZUVHUVZMZMOZIHYYMRVGI
Key (a=25, b=12) -> Decrypted Text: VGAVWIVWANANPAJIZZNSWHJ
Key (a=25, b=13) -> Decrypted Text: WHBWXJWXBOBOQBKJAAOTXIK
Key (a=25, b=14) -> Decrypted Text: XICXYKXYCPCPRCLKBBPUYJL
Key (a=25, b=15) -> Decrypted Text: YJDYZLYZDQDQSDMLCCQVZKM
Key (a=25, b=16) -> Decrypted Text: ZKEZAMZAERERTENMDDRWALN
Key (a=25, b=17) -> Decrypted Text: ALFABNABFSFSUFONEESXBMO
Key (a=25, b=18) -> Decrypted Text: BMGBCOBCGTGTVGPOFFTYCNP
Key (a=25, b=19) -> Decrypted Text: CNHCDPCDHUHUWHQPGGUZDOQ
Key (a=25, b=20) -> Decrypted Text: DOIDEQDEIVIVXIRQHHVAEPR
Key (a=25, b=21) -> Decrypted Text: EPJEFREFJWJWYJSRIIWBFQS
Key (a=25, b=22) -> Decrypted Text: FQKFGSFGKXKXZKTSJJXCGRT
Key (a=25, b=23) -> Decrypted Text: GRLGHTGHLYLYALUTKKYDHSU
Key (a=25, b=24) -> Decrypted Text: HSMHIUHIMZMZBMVULLZEITV
Key (a=25, b=25) -> Decrypted Text: ITNIJVIJNANACNWVMMAFJUW
```

Instead of reading through all of these decrypted blocks of text manually, this task is delegated to our Robot Overlords, representet by Chat GPT, to identify any sensible combinations of letters, often referred to as a proper sentence or word.

The response:

> It looks like the decrypted text is **“NOENGANGERERDETALLRIGHT”** with key $a=15$ and $b=4$, which translates to "NO EN GANG ER DET ALL RIGHT" in Norwegian, meaning "Not even once is it all right."
>
> So, the plaintext was successfully decrypted using the affine cipher with the key $(a=15, b=4)$.



One notes that the LLM does not properly separate the words into a sensible Norwegian sentence, thus making the claim of robot overlord somwhat hyperbolic as of yet, but from what the chatbot found a human would easily see that the deciphered message should be the following:
$$
\text{NOEN GANGER ER DET ALL RIGHT}
$$
The message is encrypted using the keys $(a = 15, b = 4)$



## Problem 05

Using frequency analysis on the cipher text from decode.fr:

Each character serparately:

| Letter  | Occurences | Occurence % |         |
| ------- | ---------- | ----------- | ------- |
| D       | 85×        | 18.28%      |         |
| I       | 54×        | 11.61%      |         |
| B       | 38×        | 8.17%       |         |
| K       | 33×        | 7.1%        |         |
| C       | 32×        | 6.88%       |         |
| V       | 26×        | 5.59%       |         |
| O       | 24×        | 5.16%       |         |
| Q       | 23×        | 4.95%       |         |
| W       | 22×        | 4.73%       |         |
| T       | 19×        | 4.09%       |         |
| S       | 13×        | 2.8%        |         |
| A       | 13×        | 2.8%        |         |
| E       | 10×        | 2.15%       |         |
| H       | 10×        | 2.15%       |         |
| Y       | 9×         | 1.94%       |         |
| P       | 8×         | 1.72%       |         |
| U       | 7×         | 1.51%       |         |
| M       | 7×         | 1.51%       |         |
| F       | 6×         | 1.29%       |         |
| R       | 6×         | 1.29%       |         |
| G       | 6×         | 1.29%       |         |
| J       | 6×         | 1.29%       |         |
| X       | 3×         | 0.65%       |         |
| L       | 3×         | 0.65%       |         |
| N       | 1×         | 0.22%       |         |
| Z       | 1×         | 0.22%       |         |
| #N : 26 | Σ = 465.00 | Σ = 100.04  | #N : 26 |



 Bigrams (couples of 2 characters), leaving out anything below 0,86% for brevity:

| Letter   | Occurences | Occurence % |          |
| -------- | ---------- | ----------- | -------- |
| ID       | 9×         | 3.88%       |          |
| VD       | 7×         | 3.02%       |          |
| TI       | 7×         | 3.02%       |          |
| BD       | 6×         | 2.59%       |          |
| YD       | 6×         | 2.59%       |          |
| DC       | 6×         | 2.59%       |          |
| QB       | 5×         | 2.16%       |          |
| QV       | 5×         | 2.16%       |          |
| DT       | 5×         | 2.16%       |          |
| KO       | 4×         | 1.72%       |          |
| IW       | 4×         | 1.72%       |          |
| HW       | 4×         | 1.72%       |          |
| BE       | 4×         | 1.72%       |          |
| KB       | 4×         | 1.72%       |          |
| IG       | 4×         | 1.72%       |          |
| BI       | 4×         | 1.72%       |          |
| DO       | 4×         | 1.72%       |          |
| BC       | 3×         | 1.29%       |          |
| DM       | 3×         | 1.29%       |          |
| AD       | 3×         | 1.29%       |          |
| DQ       | 3×         | 1.29%       |          |
| OK       | 3×         | 1.29%       |          |
| BA       | 3×         | 1.29%       |          |
| DB       | 3×         | 1.29%       |          |
| CD       | 3×         | 1.29%       |          |
| CU       | 3×         | 1.29%       |          |
| IB       | 2×         | 0.86%       |          |
| DI       | 2×         | 0.86%       |          |
| KV       | 2×         | 0.86%       |          |
| #N : 122 | Σ = 232.00 | Σ = 99.850  | #N : 122 |



 Trigrams (set of 3 characters), where all combinations below 1,29% were evaluated to 0,65%.

| Letter   | Occurences | Occurence % |          |
| -------- | ---------- | ----------- | -------- |
| QVD      | 3×         | 1.94%       |          |
| TID      | 3×         | 1.94%       |          |
| WIX      | 2×         | 1.29%       |          |
| SIB      | 2×         | 1.29%       |          |
| DKB      | 2×         | 1.29%       |          |
| BDH      | 2×         | 1.29%       |          |
| OKB      | 2×         | 1.29%       |          |
| ASK      | 2×         | 1.29%       |          |
| AID      | 2×         | 1.29%       |          |
| DIG      | 2×         | 1.29%       |          |
| VIB      | 2×         | 1.29%       |          |
| IBE      | 2×         | 1.29%       |          |
| UCB      | 1×         | 0.65%       |          |
| CKO      | 1×         | 0.65%       |          |
| #N : 141 | Σ = 155.00 | Σ = 100.63  | #N : 141 |

N=4 grams

| ↑↓   | ↑↓   | ↑↓    | ↑↓   |
| ---- | ---- | ----- | ---- |
| DMWC | 2×   | 1.72% |      |
| IXSI | 2×   | 1.72% |      |
| HWCU | 2×   | 1.72% |      |
| OKBA | 2×   | 1.72% |      |
| SKAI | 2×   | 1.72% |      |
| DTID | 2×   | 1.72% |      |
| UCBC | 1×   | 0.86% |      |

Based on the frequency analysis of the ciphertext, the top 10 letters and their counts are:

    D: 85 occurrences
    I: 54 occurrences
    B: 38 occurrences
    K: 33 occurrences
    C: 32 occurrences
    V: 26 occurrences
    O: 24 occurrences
    Q: 23 occurrences
    W: 22 occurrences
    T: 19 occurrences

According to [Wikipedia](https://en.wikipedia.org/wiki/Letter_frequency), the most frequent letters in English are typically **E**, **T**, **A**, **O** and **I**. 

| Letter | Relative frequency in the English language[[1\]](https://en.wikipedia.org/wiki/Letter_frequency#cite_note-micka-1) |                                                              |
| ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
|        | In texts                                                     | In dictionaries[*[citation needed](https://en.wikipedia.org/wiki/Wikipedia:Citation_needed)*] |
| **E**  | 12.7%                                                        | 11.0%                                                        |
| **T**  | 9.1%                                                         | 6.7%                                                         |
| **A**  | 8.2%                                                         | 7.8%                                                         |
| **O**  | 7.5%                                                         | 6.1%                                                         |
| **I**  | 7.0%                                                         | 8.6%                                                         |
| **N**  | 6.7%                                                         | 7.2%                                                         |
| **S**  | 6.3%                                                         | 8.7%                                                         |
| **H**  | 6.1%                                                         | 2.3%                                                         |
| **R**  | 6.0%                                                         | 7.3%                                                         |
| **D**  | 4.3%                                                         | 3.8%                                                         |

If extending this list to 10 letters (**E**, **T**, **A**, **O**, **I**, **N**, **S**, **H**, **R** and **D**) to match the list above, it is possible to make an initial assumption as follows:

- **D** could correspond to **E**, which is the most frequent letter in English.
- Alternatively, **D** could correspond to **space**, since this too is a very common character in text.
- **I** could correspond to **T**.
- **B** might correspond to **A**. `a` is an Article, thus often used on its own, not only as part of a word.
- **K** could correspond to  **O**.
- **C** could correspond to  **I**. `I` used as a pronoun often appears on its own, not only as part of a word.
- **V** could correspond to  **N**
- **O** could correspond to  **S**
- **Q** could correspond to  **H**
- **W** could correspond to  **R**
- **T** could correspond to  **D**

Table listing cipher and english letter frequency in a descending order:

| Cipher letter frequency, descending | English text letter frequency, descending | With space |
| ----------------------------------- | ----------------------------------------- | ---------- |
| D                                   | E                                         | space      |
| I                                   | T                                         | E          |
| B                                   | A                                         | T          |
| K                                   | O                                         | A          |
| C                                   | I                                         | O          |
| V                                   | N                                         | I          |
| O                                   | S                                         | N          |
| Q                                   | H                                         | S          |
| W                                   | R                                         | H          |
| T                                   | D                                         | R          |
|                                     |                                           | D          |

For bigrams:

| Cipher bigram frequency, descending | English text bigram frequency, descending |
| ----------------------------------- | ----------------------------------------- |
| ID                                  | be                                        |
| VD                                  | to                                        |
| TI                                  | of                                        |
| BD                                  | in                                        |

For trigrams:

| Cipher trigram frequency, descending | English text trigram frequency, descending |
| ------------------------------------ | ------------------------------------------ |
| QVD                                  | the                                        |
| TID                                  | and                                        |
| WIX                                  | for                                        |
| SIB                                  | not                                        |

For $n$-grams, $n = 4$:

| Cipher n=4-gram frequency, descending | English text n=4-gram frequency, descending |
| ------------------------------------- | ------------------------------------------- |
| DMWC                                  | that                                        |
| IXSI                                  | have                                        |
| HWCU                                  | with                                        |
| OKBA                                  | this                                        |

These makes for a starting point, from which to try substituting letters and sequences in the ciphertext, looking for patterns. By using the frequency analysis and doing substitution by trial and error, the following text was decrypted:

```
MONOALPHABETIC SUBSTITUTION CAN IN GENERAL EASILY BE BROKEN USING FREQUENCY ANALYSIS

THIS ONLY WORKS WELL IF THE PLAIN TEXT IS LONG ENOUGH AND IS NOT TOO DIFFERENT FROM NORMAL TEXT

ONE SHOULD ALSO KNOW WHAT LANGUAGE THE PLAIN TEXT IS WRITTEN IN, AS THE FREQUENCIES OF LETTERS VARY FROM LANGUAGE TO LANGUAGE

SOME TEXTS ARE HARDER TO BREAK THAN OTHERS

AN EXAMPLE IS THE SENTENCE THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG 
THIS SENTENCE CONTAINS EVERY LETTER OF THE ALPHABET, HELPING THE CRYPTANALYSIS

GOOD LUCK
```





#### Online Substituion Solver tool

Using an online subsitution solver service (https://www.guballa.de/substitution-solver), I was able to check the decrypted message. This substitution tool uses a Python program found here: https://gitlab.com/guballa/SubstitutionBreaker

Result from running the povided ciphertext in the substitution tool:

```
MONOALPHABE ICTSUBS I U
IONTCANTINTGENERALTEASILYTBETBROKENTUSINGTFREQUENCYTANALYSIST
HISTONLYTWORKSTWELLTIFT HETPLAIN EX TISTLONGTENOUGHTANDTISTNO T
OOTDIFFEREN TFROMTNORMALT EX TONETSHOULDTALSOTKNOWTWHA TLANGUAGET HETPLAIN
EX TISTWRI ENTINTAST HETFREQUENCIESTOFTLE ERSTVARYTFROMTLANGUAGET
OTLANGUAGETSOMET EX STARETHARDERT OTBREAKT HANTO HERSTANTEXAMPLETIST
HETSEN ENCET HETQUICKTBROWNTFOXTJUMPSTOVERT HETLAZYTDOGT HISTSEN
ENCETCON AINSTEVERYTLE ERTOFT HETALPHABE TNO THELPINGT HETCRYP
ANALYS TGOODTLUCK
```

This text obviously need some clean-up to be readable, but it's clear that there's proper english words there.

```
MONOALPHABE__ICT SUBS_I_U_ION T CAN T INT GENERAL T EASILY T BE T BROKEN T USING T FREQUENCY T ANALYSIS T

_HIS T ONLY T WORKS T WELL T IF T _HET PLAIN _EX_ T IS T LONG T ENOUGH T AND T IS T NO_ T
_OO T DIFFEREN_ T FROM T NORMAL T _EX T

ONE T SHOULD T ALSO T KNOW T WHA_ T LANGUAGE T _HE T PLAIN _EX_ T IS T WRI__EN T IN T AS T _HE T FREQUENCIES T OF T _LE__ERS T VARY T FROM T LANGUAGE T _O T LANGUAGE T 
SOME T _EX_S T ARE T HARDER T _O T BREAK T _HAN T O_HERS T 

AN T EXAMPLE T IS T _HE T SEN_ENCE T _HE T QUICK T BROWN T FOXT JUMPS T OVER T _E T LAZY T DOGT 
_HIS T SEN_ENCE T CON_AINS T EVERY T LE__ER T OF T _HE T ALPHABE__ T NO_ T HELPING T _HET CRYP_ANALYS T GOOD T LUCK
```

When going through the text, it becomes clear that `T` takes the place of `space`, which leaves all places where a `T` should occur in words empty. To make it easier to read, these places were populated with underscore `_`.

The scrubbed text:
```
MONOALPHABETIC SUBSTITUTION CAN IN GENERAL EASILY BE BROKEN USING FREQUENCY ANALYSIS

THIS ONLY WORKS WELL IF THE PLAIN TEXT IS LONG ENOUGH AND IS NOT TOO DIFFERENT FROM NORMAL TEXT

ONE SHOULD ALSO KNOW WHAT LANGUAGE THE PLAIN TEXT IS WRITTEN IN, AS THE FREQUENCIES OF LETTERS VARY FROM LANGUAGE TO LANGUAGE

SOME TEXTS ARE HARDER TO BREAK THAN OTHERS

AN EXAMPLE IS THE SENTENCE THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG 
THIS SENTENCE CONTAINS EVERY LETTER OF THE ALPHABET, HELPING THE CRYPTANALYSIS

GOOD LUCK
```

