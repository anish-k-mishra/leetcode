/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    
    let flag = false;
    return function() {
        if(flag === false){
            flag = true;
            return n;
        }
        return n = n+1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */