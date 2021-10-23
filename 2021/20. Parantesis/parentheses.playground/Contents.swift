/*
Task: 20. Valid Parentheses
 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
 
Solution:
 1. With Stack 
*/

import UIKit

// First of all let's do Stack
public struct Stack<T> {
    
    fileprivate var storage = [T]()

    public mutating func push(_ element: T) {
        storage.append(element)
    }

    public mutating func pop() -> T? {
        return storage.popLast()
    }

    public func count() -> Int {
        return storage.count
    }
}

//Solution

class Solution {
    func isValid(_ s: String) -> Bool {
        
        let openParantheses = ["[", "{", "("]
        let closeParentheses = ["]", "}", ")"]
        let parenthesesMatch = ["[": "]",
                                "{": "}",
                                "(": ")"]
        
        var stack = Stack<String>()
        var index = s.startIndex
        
        while index != s.endIndex {
            if openParantheses.contains(String(s[index])) {
                stack.push(String(s[index]))
                index = s.index(after: index)
                continue
            }
            
            if closeParentheses.contains(String(s[index])) {
                guard let openBracket = stack.pop() else { return false}
                let matchedClosed = parenthesesMatch[openBracket]!
                if matchedClosed == String(s[index]) {
                    index = s.index(after: index)
                    continue
                } else {
                    return false
                }
            }
        }
        
        return stack.count() == 0
    }
}

Solution().isValid("{{")

/* What to learn:
 - String and Substring with differences
 - Mark mutating functions
 - Forgot about only open parantheses 
*/
