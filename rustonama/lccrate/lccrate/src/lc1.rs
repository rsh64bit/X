/*
 * @lc app=leetcode id=1 lang=rust
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.28%)
 * Total Accepted:    2.8M
 * Total Submissions: 6.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
*/

/*
Approach:
- Sliding window does not apply because this is not a contiguous subarray problem.
- Two pointers needs sorted input, which would lose original indices.
- Use a hashmap to store seen number -> index, and check complement in O(1).
*/

pub mod dev {
    use std::collections::HashMap;

    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut sum_hash = HashMap::new();
    let mut pair: Vec<i32> = Vec::new();
    for (i, val) in nums.iter().enumerate() {
        if sum_hash.contains_key
        (&(target - val)) {
            match sum_hash.get(&(target - val)) {
                Some(v) => {
                    pair.push(i.try_into().unwrap());
                    pair.push(*v);
                }
                None => {
                    println!("wtf");
                }
            }
        } else {
            sum_hash.insert(val, i.try_into().unwrap());
        }
    }
    pair
}
}

pub mod ai {
    use std::collections::HashMap;

    // copilot improvements
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut seen: HashMap<i32, usize> = HashMap::new();

    for (i, &value) in nums.iter().enumerate() {
        let needed = target - value;

        if let Some(&j) = seen.get(&needed) {
            return vec![j as i32, i as i32];
        }

        seen.insert(value, i);
    }

    Vec::new()
}
}
