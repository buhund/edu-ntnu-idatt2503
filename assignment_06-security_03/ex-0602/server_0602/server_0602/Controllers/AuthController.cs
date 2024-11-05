using Microsoft.AspNetCore.Mvc;
using System.Security.Cryptography;
using System.Text;

namespace server_0602.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class AuthController : ControllerBase
    {
        private static readonly string ServerSalt = "server_specific_salt";

        // POST: api/auth/login
        [HttpPost("login")]
        public IActionResult Login([FromBody] LoginRequest request)
        {
            Console.WriteLine($"Received client hashed password (Base64): {request.HashedPassword}");

            // Decode the Base64-encoded client hash into binary form
            byte[] clientHashedBytes = Convert.FromBase64String(request.HashedPassword);

            // Simulate retrieving the stored hash, as defined during user registration
            string storedHash = GetStoredHash();

            // To simulate a stored password, we have hardcoded the password "Password123" and combine it with
            // the same salt as on client side, then hash it:
            //     hash(password + client_salt) = client_hashed_pw
            // I think I'm doing something wrong in the hashing, but I can't get it to work when trying to
            // properly wrap the hashing for hash(hash(pw + client_salt)+server_salt)
            string serverHashedPassword = HashWithPbkdf2("Password123", "client_specific_salt", ServerSalt);

            Console.WriteLine($"Stored hash: {storedHash}");
            Console.WriteLine($"Server re-hashed password: {serverHashedPassword}");

            // Compare the final server-side hashed password with the stored hash (simulated client-provided hash)
            if (storedHash == serverHashedPassword)
            {
                Console.WriteLine("Authentication successful");
                return Ok(new { message = "Authentication successful!" });
            }
            else
            {
                Console.WriteLine("Authentication failed");
                return Unauthorized(new { message = "Authentication failed!" });
            }
        }

        // Simulate retrieving the stored password from the database, as hashed upon user registration
        private string GetStoredHash()
        {
            // Stored hash = the password hashed first with client salt, then with server salt, 
            // simulating a database of sorts.
            return HashWithPbkdf2("Password123", "client_specific_salt", ServerSalt);
        }

        // Hash a password (string) using PBKDF2 with client and server salt
        private string HashWithPbkdf2(string password, string clientSalt, string serverSalt)
        {
            // First we hash the password with the client salt
            byte[] clientSaltBytes = Encoding.UTF8.GetBytes(clientSalt);
            using (var rfc2898Client = new Rfc2898DeriveBytes(password, clientSaltBytes, 2048, HashAlgorithmName.SHA256))
            {
                byte[] clientHashedBytes = rfc2898Client.GetBytes(32);

                // Then we hash the result with the server salt
                byte[] serverSaltBytes = Encoding.UTF8.GetBytes(serverSalt);
                using (var rfc2898Server = new Rfc2898DeriveBytes(clientHashedBytes, serverSaltBytes, 2048, HashAlgorithmName.SHA256))
                {
                    return Convert.ToBase64String(rfc2898Server.GetBytes(32));
                }
            }
        }
    }

    public class LoginRequest
    {
        public string? HashedPassword { get; set; }  // Nullable because reasons
    }
}
