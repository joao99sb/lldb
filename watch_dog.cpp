#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
#include <sys/stat.h> // For stat function on Unix-based systems
#include <unistd.h>   // Para as funções fork(), execvp(), getpid() e usleep()
#include <sys/wait.h>

// Função que será executada quando a mudança no arquivo for detectada
void fileChangedCallback()
{
  std::cout << "Arquivo modificado! Recompilando..." << std::endl;
  std::system("make debug");                           // Execute the "make debug" command
  std::cout << "Recompilação concluída!" << std::endl; // Adicione o código que você deseja executar quando o arquivo for modificado
}

// Função para obter a data e hora da última modificação do arquivo
std::time_t getLastModifiedTime(const std::string &filePath)
{
  struct stat result;
  if (stat(filePath.c_str(), &result) == 0)
  {
    return result.st_mtime;
  }
  return 0; // Retorna 0 em caso de erro
}

// Função para observar a mudança no arquivo
void observeFileChange(const std::string &filePath, std::function<void()> callback)
{
  std::time_t lastWriteTime = getLastModifiedTime(filePath);

  while (true)
  {
    // std::this_thread::sleep_for(std::chrono::seconds(1)); // Aguarda por 1 segundo antes de verificar novamente

    std::time_t newWriteTime = getLastModifiedTime(filePath);
    if (newWriteTime != lastWriteTime)
    {
      lastWriteTime = newWriteTime;
      callback(); // Dispara a função de callback
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Uso: " << argv[0] << " <caminho_do_arquivo>" << std::endl;
    return 1;
  }

  pid_t child_pid = fork();

  if (child_pid == -1)
  {
    std::cerr << "Erro ao criar o processo filho." << std::endl;
    return 1;
  }
  std::string filePath = argv[1]; // Use the provided file path from command-line argument

  
  
  
  
  
  
  // Usando uma lambda como callback
  observeFileChange(filePath, []()
                    { fileChangedCallback(); });

  return 0;
}
