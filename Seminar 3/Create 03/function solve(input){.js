function solve(input) {
    let numberOfCases = input.shift();
  
    for (let Case = 0; Case < numberOfCases; Case++) {
      let [numberOfSticks, numberOfLines] = input.shift();
      let sticks = new Array(numberOfSticks + 1).fill(0);
      let order = [];
  
      for (let j = 0; j < numberOfLines; j++) {
        let [stick1, stick2] = input.shift();
  
        sticks[stick1]++;
      }
  
      for (let i = 1; i <= numberOfSticks; i++) {
        if (sticks[i] === 0) {
          order.push(i);
          sticks[i] = -1; // Mark as processed
          i = 0; // Restart the loop to recheck for newly uncovered sticks
        }
      }
  
      if (order.length !== numberOfSticks) {
        console.log(`Case ${Case + 1}: No valid ordering found`);
      } else {
        console.log(`Case ${Case + 1}: ${order.join(" ")}`);
      }
    }
  }

    solve([2,
        [10, 6],
        [8, 5],
        [4, 8],
        [3, 8],
        [2, 7],
        [6, 8],
        [3, 7],
        [8, 14],
        [0, 4],
        [3, 7],
        [2, 6],
        [4, 3],
        [5, 7],
        [4, 5],
        [1, 7],
        [6, 3],
        [2, 3],
        [4, 7],
        [6, 7],
        [1, 2],
        [2, 7],
        [0, 7]
    ])