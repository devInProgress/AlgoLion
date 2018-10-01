const evaluateSum = (n) => {
  return n * (n + 1) / 2;
}

const main = () => {
  const sum = evaluateSum(100);
  console.log(sum);
}

main();