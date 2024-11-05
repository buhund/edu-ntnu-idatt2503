using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;

var builder = WebApplication.CreateBuilder(args);

// CORS policy to allow all origins
builder.Services.AddCors(options =>
{
    options.AddPolicy("AllowAllOrigins", builder =>
    {
        builder.AllowAnyOrigin()
            .AllowAnyMethod()
            .AllowAnyHeader();
    });
});

// Add controller services
builder.Services.AddControllers();

var app = builder.Build();

// Apply CORS policy
app.UseCors("AllowAllOrigins");

// Map the controller endpoints
app.MapControllers();

// Run Forrest, run!
app.Run();