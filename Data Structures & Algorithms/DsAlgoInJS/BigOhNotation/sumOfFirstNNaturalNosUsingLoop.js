const evaluateSum = (n) => {
  let total = 0;
  for (let i = 0; i < n; i++) {
    total += i + 1;
  }
  return total;
}

const main = () => {
  const sum = evaluateSum(100);
  console.log(sum);
}

main();

