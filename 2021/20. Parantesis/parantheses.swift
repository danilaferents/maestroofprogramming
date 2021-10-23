// Code redacror without highlighting
// First of all let's do Stack 
public struct Stack<T> {
	
	fileprivate var storage = [T]()

	public func push(_ element: T) {
		storage.append(element)
	} 

	public func pop() -> T? {
		return array.popLast()
	}

	public func count() -> Int {
		return array.count
	}
}

//Solution 

class Solution {
    func isValid(_ s: String) -> Bool {
        
        let openParantheses = ['[', '{', '(']
        let closeParentheses = [']', '}', ')']
        let parenthesesMatch = ['[': ']',
                                '{', '}',
                                '(', ')']
        
        let stack = Stack()
        let index = s.startIndex
        
        while startIndex != s.endIndex {
            if openParantheses.contains(s[index]) {
                stack.push(s[index])
                index = s.index(after: index)
                continue
            }
            
            if closeParentheses.contains(s[index]) {
                let openBracket = stack.pop()
                let matchedClosed = parenthesesMatch[openBracket]!
                if matchedClosed == s[index] {
                    index = s.index(after: index)
                    continue
                } else {
                    return false
                }
            }
        }
        
        return true
    }
}
