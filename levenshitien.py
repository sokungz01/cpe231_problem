import subprocess
import random
import string


# Compile the C program if needed
# subprocess.run(["gcc", "minimumDistance.c", "-o", "minimumDistance"])
# subprocess.run(["gcc", "min-dist.c", "-o", "min-dist"])

def generate_test_case():
    # Generate your test case here
    # For example, you can generate random input data
    # and return it as a string in the format expected by your C program
    characters = string.ascii_letters
    test_case = f''
    n1 = random.randint(1,100)
    n2 = random.randint(1,100)
    a = ''.join(random.choice(characters) for _ in range(n1))
    b = ''.join(random.choice(characters) for _ in range(n2))
    test_case += f'{a}\n{b}'

    return test_case

def run_c_program_with_input(program, input_data):
    # Run the C program and capture its output
    process = subprocess.Popen([program], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input=input_data)
    return stdout, stderr

def main():
    # Generate a test case
    test_input = generate_test_case()

    # Run the C program with the generated input
    c_output1, c_error = run_c_program_with_input("testSorn.exe",test_input)
    # c_output2, c_error = run_c_program_with_input("./mint-dist-dnq",test_input)

    # Define the expected output (replace with the expected result)
    expected_output, c_error2 = run_c_program_with_input("levenshtien.exe",test_input)
    print(f'{c_output1.strip()}: {expected_output}')

    # Compare the C program's output with the expected output
    if c_output1.strip() == expected_output.strip():
        # print("Test Passed")
        return True, []
    else:
        print("Test Failed")
        return False, test_input

if __name__ == "__main__":
  for i in range(10000):
    print(f'{i}: ',end='')
    res, test_input = main()
    if not res:
       with open('levenshitien_err_input.txt','w') as f:
          f.write(test_input)
      #  print(test_input)
       break