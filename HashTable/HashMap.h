// h(n) = n mod p
// p = prime and it should be bigger than any other number in the string
// k = window size
// n = number in actual window
// old = number that with want to remove
// new = number we want to concatenate

// new n = ((old n) - old * base^(k - 1)) * base + new
// new n = (old n) * base - old * base^k + new

// hash(of new n) = (new n) mod p
// hash(of new n) = ((old n) * base - old * base^k + new) mod p
// hash(of new n) = (((old n) mod p) * base - old * (base^k mod p) + new) mod p

// (old n) mod p = (hash of old n)
// (base^k mod p) = magic // we can precompute it

// append:
// 	hash(of new n without removing the numbers to the left) =  (((hash of old n) * base) + new) mod p
//	magic = (magic * base) mod p

// skip:
//	hash(of new n without adding a number to the right but removing a left one) = ((hash of old n) - old * magic + p * base ) mod p // ( + p * base ) can be replaced by ( + p * old)
//	magic = (modular inverse of base) mod p

 
