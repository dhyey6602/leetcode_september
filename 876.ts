// 876. Middle of the Linked List

/**
 Do not return anything, modify nums in-place instead.
 */
 function moveZeroes(nums: number[]): void {
    if (nums.length !== 1) {
        let i = nums.length - 2

        const moveElementToEnd = (nums: number[], index) => {
            let j = index

            while (j < nums.length - 1) {
                const tmp = nums[j + 1]
                nums[j + 1] = nums[j]
                nums[j] = tmp
                
                j += 1
            }
        }

        while (i >= 0) {
            if (nums[i] === 0) {
                moveElementToEnd(nums, i)
            }
            
            i -= 1
        }
    }
};
