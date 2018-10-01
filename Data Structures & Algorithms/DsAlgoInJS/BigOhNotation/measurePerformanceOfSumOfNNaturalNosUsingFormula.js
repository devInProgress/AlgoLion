const evaluateSum = (n) => {
  return n * (n + 1) / 2;
}

const main = () => {
  const timeBeforeEvalution = performance.now()
  const sum = evaluateSum(1000000000);
  const timeAfterEvaluation = performance.now();
  console.log(`Time Elapsed: ${(timeAfterEvaluation - timeBeforeEvalution) / 1000} seconds.`);
}

main();