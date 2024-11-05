document.getElementById("loginForm").addEventListener("submit", async function (e) {
    e.preventDefault();

    // Password input field
    const password = document.getElementById("password").value;

    // Hard-coded salt, same as is hard coded on the server
    const clientSalt = "client_specific_salt";

    // Hash the password using PBKDF2 on the client side
    const hashedPassword = CryptoJS.PBKDF2(password, clientSalt, {
        keySize: 256 / 32,
        iterations: 2048,
    // Directly convert to Base64
    }).toString(CryptoJS.enc.Base64);

    console.log("Client-side hashed password (Base64):", hashedPassword);

    // Send the Base64 hashed password to the server
    try {
        const response = await fetch("http://localhost:5000/api/auth/login", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            // Send the Base64 hashed password
            body: JSON.stringify({ hashedPassword }),
        });

        if (!response.ok) {
            throw new Error('Network response was not ok');
        }

        const result = await response.json();
        console.log("Server response:", result);
    } catch (error) {
        console.error("There was a problem with the fetch operation:", error);
    }
});
