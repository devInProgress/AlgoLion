const evaluateSum = (n) => {
  let total = 0;
  for (let i = 0; i < n; i++) {
    total += i + 1;
  }
  return total;
}

const main = () => {
  const timeBeforeEvalution = performance.now();
  const sum = evaluateSum(1000000000);
  const timeAfterEvaluation = performance.now();
  console.log(`Time Elapsed: ${(timeAfterEvaluation - timeBeforeEvalution) / 1000} seconds.`);
}

main();

