import hashlib
import itertools
import string

# Warnings and stuff
print("Welcome to Password Dragon-Force py_XT-2000 Pro Elite Plus.")
print("Terms and conditions:")
print("You are not allowed to use this program to create nuclear or chemical weapons.")
print("By having run this program, you are legally bound to never ever make and/or use nuclear and/or chemical weapons.")
print("---------")
print("WARNING! Starting the secret Crack-A-DragonMole py_XT2000(TM) process. Please stand by.")
print("ACHTUNG! Black Holes may appear in the vicinity of the computation device. Do not be alarmed, they are friendly.")
print("")


# Known parameters from the assignment.
target_hash = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6"
salt = b"Saltet til Ola" # Coding the salt as a byte string by using b in front of the string. Such code, very pro.
iterations = 2048
max_password_length = 6  # Lecture said the password isn't super long. "No need to try for more than 7 letters."

# Character set for brute-force. Using both upper and lower case letters, digits.
# Assuming there's no fancy special characters, that we're not supposed to spend 3 weeks cracking the password :D
charset = string.ascii_letters + string.digits

# Computes the PBKDF2-HMAC-SHA1 hash of the password using the provided salt and number of iterations.
def compute_pbkdf2_sha1(password, salt, iterations):
    # The password is first encoded to bytes, then hashed, and the result is returned as a hexadecimal string.
    return hashlib.pbkdf2_hmac('sha1', password.encode(), salt, iterations).hex()

# Brute-force password cracking.
# Running through all letters and digits up to the given length.
def password_cracker(target_hash, salt, iterations):

    # For-loop, looping over possible password lengths, from 1 up to max_password_length.
    for password_length in range(1, max_password_length + 1):

        # Run throuhgh all possible combinations of characters at the current length.
        for password in itertools.product(charset, repeat=password_length):

            # Join the tuple of characters into a string to create the current guess.
            password = ''.join(password)

            # Compute the hash of the guessed password.
            hash_value = compute_pbkdf2_sha1(password, salt, iterations)

            # Compare the hashed guess to the provided hash to check if we found the correct password.
            if hash_value == target_hash:
                return password
        print(f"Checked all passwords of length: {password_length}")
    return None

# Function call to start the cracking rocess by throwing the known parameters into the password_cracker function.
cracked_password = password_cracker(target_hash, salt, iterations)

# Great success? Yes, no?
if cracked_password:
    print(f"Cracked password: {cracked_password}")
    print("Thank you for using Password Dragon-Force py_XT-2000 Pro Elite Plus for your highly legal password cracking.")
else:
    print("Password not found")
    print("¯\_(ツ)_/¯")
    print("Since the program failed, you problably used Password Chichen, the umbrella term for software from our competitors.")
