import subprocess
import random


# Compile the C program if needed
# subprocess.run(["gcc", "minimumDistance.c", "-o", "minimumDistance"])
# subprocess.run(["gcc", "min-dist.c", "-o", "min-dist"])

def generate_test_case():
    # Generate your test case here
    # For example, you can generate random input data
    # and return it as a string in the format expected by your C program
    n = random.randint(2,10)
    test_case = f'{n}\n'
    for i in range(n):
      a = random.uniform(-1000,1000)
      b = random.uniform(-1000,1000)
      test_case += f'{a} {b}\n'

    return test_case, n

def run_c_program_with_input(program, input_data):
    # Run the C program and capture its output
    process = subprocess.Popen([program], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input=input_data)
    return stdout, stderr

def main():
    # Generate a test case
    test_input, n = generate_test_case()

    # Run the C program with the generated input
    c_output1, c_error = run_c_program_with_input("minimumPark.exe",test_input)
    # c_output2, c_error = run_c_program_with_input("./mint-dist-dnq",test_input)

    # Define the expected output (replace with the expected result)
    expected_output, c_error2 = run_c_program_with_input("minimumDistance.exe",test_input)
    print(f'{c_output1.strip()}: {expected_output}')

    # Compare the C program's output with the expected output
    if c_output1.strip() == expected_output.strip():
        # print("Test Passed")
        return True, []
    else:
        print("Test Failed")
        return False, test_input

if __name__ == "__main__":
  for i in range(1000):
    print(f'{i}: ',end='')
    res, test_input = main()
    if not res:
       with open('closestpair_err_input.txt','w') as f:
          f.write(test_input)
      #  print(test_input)
       break