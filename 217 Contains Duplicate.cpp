class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};


//map solution

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         for(const auto& pair: mp){
//             if(pair.second>1)return true;
//         }
//         return false;
//     }
// };


// Time and space complexity for different data structures.
// map : 75.84mb, 134ms
// unordered_map : 75.21mb, 100ms
// unordered_set : 73.2mb, 88ms -> optimized.
// set : 73.12mb, 109ms

//for map and set solutions the unordered part.


//LLM notes

//note 1

/*
In C++, `map`, `unordered_map`, and `set` are standard library containers used to store data, but they have different properties and use cases:

### 1. `map`
- **Type:** Associative container
- **Key Characteristics:**
  - Stores key-value pairs.
  - Maintains order based on keys using a sorted sequence (typically implemented with a red-black tree).
  - Each key must be unique.
  - Searching, insertion, and deletion operations have logarithmic time complexity (\(O(\log n)\)).
  - Keys are immutable.
- **Use Case:** Use a `map` when you need ordered, associative data storage with key-value pairs, and you might benefit from the natural ordering of keys for operations like range queries.

### 2. `unordered_map`
- **Type:** Associative container
- **Key Characteristics:**
  - Stores key-value pairs.
  - Uses a hash table for storage, which means it does not maintain any order.
  - Each key must be unique.
  - Provides average constant time complexity (\(O(1)\)) for search, insert, and delete operations under ideal conditions; worst case is linear time complexity (\(O(n)\)).
  - Keys are immutable.
- **Use Case:** Use an `unordered_map` when you need fast access to your elements by key without needing any order among the elements. It's efficient for lookups, insertions, and deletions when the hash function is good and reduces collisions.

### 3. `set`
- **Type:** Associative container
- **Key Characteristics:**
  - Stores unique elements (like a mathematical set).
  - Maintains order of the elements based on their value using a sorted sequence (typically implemented with a red-black tree).
  - Searching, insertion, and deletion operations have logarithmic time complexity (\(O(\log n)\)).
- **Use Case:** Use a `set` when you need to maintain a collection of unique items with automatic sorting. It is especially useful when you frequently check for the existence of an item.

### Summary
- Use a **map** if you need a sorted collection of unique key-value pairs.
- Use an **unordered_map** for faster access where the order is not a concern.
- Use a **set** for a sorted collection of unique elements without additional associated data.

Each of these containers can be highly useful depending on the specific requirements of your application, such as performance needs and operations on data.
*/

//note 2
/*
In terms of algorithmic complexity, \( O(1) \) represents constant time complexity, while \( O(\log n) \) represents logarithmic time complexity. 

1. **\( O(1) \) - Constant Time**: This means the time required to complete the operation does not depend on the size of the input data set. It is always the same, making it the ideal scenario for efficiency in most cases.

2. **\( O(\log n) \) - Logarithmic Time**: This complexity implies that the time it takes to complete the operation increases logarithmically as the size of the input data increases. It's more efficient than linear time (\( O(n) \)), but less efficient compared to constant time for larger data sets.

Comparing these two:
- \( O(1) \) is considered faster and more efficient than \( O(\log n) \) because operations with \( O(1) \) complexity will generally take the same amount of time regardless of the input size, while \( O(\log n) \) operations take more time as the size of the input grows, albeit at a slow rate.

In summary, \( O(1) \) is greater in terms of efficiency compared to \( O(\log n) \).
*/


//note 3

/*
The C++ code snippet you provided uses an `unordered_set` to determine if there are any duplicate elements in a vector (or array-like structure) called `nums`. Here's a step-by-step explanation of how it works:

### Code Components:
1. **`unordered_set<int> s;`**
   - This line declares an `unordered_set` named `s` that will store integers. An `unordered_set` is a container that stores unique elements in no particular order. The operations to insert elements and find elements in an `unordered_set` typically have an average time complexity of \(O(1)\).

2. **Loop through each element in `nums`:**
   - `for (int i = 0; i < nums.size(); i++) { ... }`
   - This for loop iterates over each element of the container `nums` from the first element (index 0) to the last. The `nums.size()` function returns the number of elements in `nums`.

3. **Check for duplicates using `s.find(nums[i])`:**
   - `if (s.find(nums[i]) != s.end()) { return true; }`
   - Inside the loop, each element `nums[i]` is checked to see if it already exists in the set `s`.
   - The `find` method attempts to locate the element in the set. If the element is found, `find` returns an iterator pointing to the element within the set. If the element is not found, it returns an iterator equal to `s.end()` (the iterator one past the last element).
   - If `find` does not return `s.end()`, it means the element was found in the set, indicating a duplicate. Thus, the function immediately returns `true`.

4. **Insert the current element into the set:**
   - `s.insert(nums[i]);`
   - If the current element `nums[i]` is not already in the set, it is added to the set using the `insert` method. This ensures that any future occurrence of this element in `nums` will be detected as a duplicate.

5. **Return false if no duplicates are found:**
   - `return false;`
   - If the loop completes without finding any duplicates (i.e., without ever returning `true`), the function returns `false`, indicating that there are no duplicate elements in `nums`.

### Overall Functionality:
The code effectively checks for duplicate values in the array `nums` using an `unordered_set` to store and quickly check for previously encountered elements. This method is efficient, taking advantage of the fast lookup, insert, and check operations provided by `unordered_set`, typically in constant average time complexity.

This pattern is common in problems involving detection of duplicates or seen values in a sequence and is useful in a variety of algorithmic challenges or situations where quick membership testing is necessary.
*/

//note 4
/*
In C++, both `set` and `unordered_set` are part of the Standard Template Library (STL) and are used to store unique elements. However, they differ significantly in their internal implementation, properties, and performance characteristics. Here's a detailed comparison:

### 1. Implementation and Order

**`set`:**
- **Implementation:** `set` is typically implemented using a balanced binary search tree (such as a Red-Black Tree).
- **Order:** The elements in a `set` are stored in a sorted order according to their value. This order is determined by the comparison function, which by default is `std::less<T>`, meaning the elements are stored in ascending order.

**`unordered_set`:**
- **Implementation:** `unordered_set` uses a hash table as its underlying data structure.
- **Order:** There is no order among elements in an `unordered_set`; they are stored in an arbitrary order that depends on the hash function and the internal bucket structure. This can change as elements are added or removed.

### 2. Performance

**`set`:**
- **Access, Search, Insertion, and Deletion:** Operations like search, insertion, and deletion have a time complexity of \(O(\log n)\), where \(n\) is the number of elements in the container.

**`unordered_set`:**
- **Access, Search, Insertion, and Deletion:** These operations generally have an average time complexity of \(O(1)\). In the worst case (when a hash collision occurs), the complexity can degrade to \(O(n)\), but this is rare with a good hash function and proper resizing rules.

### 3. Usage Scenario

**`set`:**
- Use `set` when you need the elements to be sorted automatically, or when you frequently perform operations that rely on ordering (like finding the lower or upper bound of a value).
- Suitable for applications where the order of the elements matters, such as when you need to maintain a sorted list of unique items.

**`unordered_set`:**
- Choose `unordered_set` when you need faster access and the order of elements does not matter.
- Ideal for cases where you need to check membership quickly and the insertion and deletion performance is critical, without the need for sorting or ordering elements.

### 4. Memory Usage

**`set`:**
- Generally, `set` might use more memory compared to `unordered_set` due to the structure of the binary search tree, which needs to store pointers to child nodes and maintain balance.

**`unordered_set`:**
- Uses memory for buckets in the hash table, which can be more efficient, but also potentially wasteful if the load factor is not well managed (e.g., too many empty buckets).

### 5. Flexibility with the Key Type

**`set`:**
- Requires that the key type be comparable using a comparison function (`std::less<T>` by default).

**`unordered_set`:**
- Requires that the key type be hashable, which means there must be a specialization of `std::hash<T>` available. You can also provide a custom hash function.

In summary, the choice between `set` and `unordered_set` should be based on the requirements for element ordering, performance constraints, and the nature of operations typically performed with the container. Each offers distinct advantages that can be leveraged depending on the specific needs of your application.
*/