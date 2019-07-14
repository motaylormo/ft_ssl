# MD5
### Rounds
```
0 ≤ i ≤ 15
	F(b, c, d) = (b ∧ c) ∨ (¬b ∧ d)
	g = i
	s = {7, 12, 17, 22}
16 ≤ i ≤ 31
	F(b, c, d) = (b ∧ d) ∨ (c ∧ ¬d)
	g = (5 * i + 1) % 16
	s = {5, 9, 14, 20}
32 ≤ i ≤ 47
	F(b, c, d) = b ⊕ c ⊕ d
	g = (3 * i + 5) % 16
	s = {4, 11, 16, 23}
48 ≤ i ≤ 63
	F(b, c, d) = c ⊕ (b ∨ ¬d)
	g = (7 * i) % 16
	s = {6, 10, 15, 21}
```
### Compression function
```
tmp = b + RotLˢ⁽ⁱ⁾(a + F(b,c,d) + K[i] + W[g])
a = d
d = c
c = b
b = tmp
```

# SHA-1
### Words
```
16 ≤ i ≤ 79
	W[i] = RotL¹(W[i - 3] ⊕ W[i - 8] ⊕ W[i - 14] ⊕ W[i - 16])
```
### Rounds
```
0 ≤ i ≤ 19
	F(b, c, d) = Ch(b, c, d)
	K = 5a827999
20 ≤ i ≤ 39
	F(b, c, d) = Par(b, c, d)
	K = 6ed9eba1
40 ≤ i ≤ 59
	F(b, c, d) = Maj(b, c, d)
	K = 8f1bbcdc
60 ≤ i ≤ 79
	F(b, c, d) = Par(b, c, d)
	K = ca62c1d6
```
### Compression function
```
tmp = RotL⁵(a) + F(b,c,d) + W[i] + K + e
e = d
d = c
c = RotL³⁰(b)
b = a
a = tmp
```

# SHA-256
```
Maj(x, y, z) = (x ∧ y) ⊕ (x ∧ z) ⊕ (y ∧ z)
Ch(x, y, z) = (x ∧ y) ⊕ (¬x ∧ z)

Σ₀(x) =  RotR²(x) ⊕ RotR¹³(x) ⊕ RotR²²(x)
Σ₁(x) =  RotR⁶(x) ⊕ RotR¹¹(x) ⊕ RotR²⁵(x)
σ₀(x) =  RotR⁷(x) ⊕ RotR¹⁸(x) ⊕ ShiftR³(x)
σ₁(x) = RotR¹⁷(x) ⊕ RotR¹⁹(x) ⊕ ShiftR¹⁰(x)
```
### Words
```
16 ≤ i ≤ 63
	W[i] = σ₁(W[i - 2]) + W[i - 7] + σ₀(W[i - 15]) + W[i - 16]
```
### Compression function
```
tmp1 = h + Σ₁(e) + Ch(e,f,g) + K[i] + W[i]
tmp2 = Σ₀(a) + Maj(a,b,c)
h = g
g = f
f = e
e = d + tmp1
d = c
c = b
b = a
a = tmp1 + tmp2
```

# SHA-512
```
Maj(x, y, z) = (x ∧ y) ⊕ (x ∧ z) ⊕ (y ∧ z)
Ch(x, y, z) = (x ∧ y) ⊕ (¬x ∧ z)

Σ₀(x) = RotR²⁸(x) ⊕ RotR³⁴(x) ⊕ RotR³⁹(x)
Σ₁(x) = RotR¹⁴(x) ⊕ RotR¹⁸(x) ⊕ RotR⁴¹(x)
σ₀(x) =  RotR¹(x) ⊕  RotR⁸(x) ⊕ ShiftR⁷(x)
σ₁(x) = RotR¹⁹(x) ⊕ RotR⁶¹(x) ⊕ ShiftR⁶(x)
```
### Words
```
16 ≤ i ≤ 79
	W[i] = σ₁(W[i - 2]) + W[i - 7] + σ₀(W[i - 15]) + W[i - 16]
```
### Compression
```
tmp1 = h + Σ₁(e) + Ch(e,f,g) + K[i] + W[i]
tmp2 = Σ₀(a) + Maj(a,b,c)
h = g
g = f
f = e
e = d + tmp1
d = c
c = b
b = a
a = tmp1 + tmp2
```