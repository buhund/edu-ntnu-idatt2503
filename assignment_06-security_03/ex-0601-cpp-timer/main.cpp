#include <iostream>
#include <openssl/evp.h>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <openssl/kdf.h>
#include <openssl/err.h>
#include <chrono>  // For measuring time

// Converts a byte array to a hexadecimal string
std::string to_hex(const unsigned char* hash, size_t length) {
  std::stringstream ss;
  for (size_t i = 0; i < length; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  return ss.str();
}

// PBKDF2-SHA1 function
std::string pbkdf2_sha1(const std::string& password, const std::string& salt, int iterations) {
  unsigned char derived_key[20];  // PBKDF2 with SHA-1 produces a 160-bit (20-byte) key
  PKCS5_PBKDF2_HMAC(password.c_str(), password.length(), reinterpret_cast<const unsigned char*>(salt.c_str()), salt.length(), iterations, EVP_sha1(), 20, derived_key);
  return to_hex(derived_key, 20);
}

// Brute-force search for password
bool brute_force(const std::string& target_hash, const std::string& salt, int iterations, const std::string& charset, std::string current_password, int max_length, unsigned long long& counter) {
  if (current_password.length() > max_length) {
    return false;
  }

  // Check the current password
  std::string hash = pbkdf2_sha1(current_password, salt, iterations);
  counter++;

  if (hash == target_hash) {
    std::cout << "Password found: " << current_password << std::endl;
    return true;  // Return true to indicate password was found
  }

  // Recursively try all characters from the charset
  for (char c : charset) {
    if (brute_force(target_hash, salt, iterations, charset, current_password + c, max_length, counter)) {
      return true;  // If password is found, propagate the result up
    }
  }

  return false;  // Password not found at this level
}

// Wrapper function to track progress, time, and number of passwords checked
void brute_force_with_progress(const std::string& target_hash, const std::string& salt, int iterations, const std::string& charset, int max_length) {
  for (int length = 1; length <= max_length; ++length) {
    std::cout << "Checking all passwords of length: " << length << std::endl;

    // Measure time
    auto start = std::chrono::high_resolution_clock::now();

    unsigned long long counter = 0;
    if (brute_force(target_hash, salt, iterations, charset, "", length, counter)) {
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> elapsed = end - start;
      std::cout << "Time taken for length " << length << ": " << elapsed.count() << " seconds" << std::endl;
      std::cout << "Passwords checked for length " << length << ": " << counter << std::endl;
      return;  // Stop the search once the password is found
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken for length " << length << ": " << elapsed.count() << " seconds" << std::endl;
    std::cout << "Passwords checked for length " << length << ": " << counter << std::endl;
  }
}

int main() {
  // Known values
  std::string target_hash = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";
  std::string salt = "Saltet til Ola";
  int iterations = 2048;

  // Character set for brute-force (lowercase, uppercase, and digits)
  std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  // Maximum password length to try
  int max_password_length = 4;

  // Start brute-force search with progress printing
  brute_force_with_progress(target_hash, salt, iterations, charset, max_password_length);

  std::cout << "Password not found." << std::endl;
  return 0;
}
