#!/bin/bash
# Script específico para compilar dog.c do GitHub

set -e

# Configuração
REPO_URL="https://github.com/TotonhoMilk/dog.git"
SOURCE_FILE="dev/main.c"
OUTPUT_NAME="dog"

# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

echo "📦 Baixando e compilando $SOURCE_FILE..."

# Cria diretório temporário
TEMP_DIR=$(mktemp -d)
cd "$TEMP_DIR"

# Baixa do GitHub
if [[ "$REPO_URL" == *".git" ]]; then
  git clone --depth 1 "$REPO_URL" projeto
else
  git clone --depth 1 "${REPO_URL}.git" projeto
fi

cd projeto

# Verifica se o arquivo existe
if [[ ! -f "$SOURCE_FILE" ]]; then
  echo -e "${RED}❌ Arquivo $SOURCE_FILE não encontrado${NC}"
  echo "Arquivos disponíveis:"
  ls -la *.c 2>/dev/null || ls -la
  exit 1
fi

# Compila
echo "🔨 Compilando com GCC..."
gcc -Wall -Wextra -O2 "$SOURCE_FILE" -o "$OUTPUT_NAME"

# Verifica se compilou
if [[ -f "$OUTPUT_NAME" ]]; then
  echo -e "${GREEN}✅ Compilação bem-sucedida!${NC}"

  # Instala localmente
  mkdir -p ~/.local/bin
  cp "$OUTPUT_NAME" ~/.local/bin/
  chmod +x ~/.local/bin/"$OUTPUT_NAME"

  # Copia os arquivos de ajuda e versão
  # mkdir -p ~/.local/bin/docs
  cp -r -f docs/ ~/.local/bin/

  echo ""
  echo "📌 Binário instalado em: ~/.local/bin/$OUTPUT_NAME"
  echo "🚀 Execute com: $OUTPUT_NAME"
  echo ""
  echo "🐕 DOG - The Rebellious Cat Clone"
  echo "Woof! Woof!"
else
  echo -e "${RED}❌ Falha na compilação${NC}"
fi

# Limpa
echo ""
echo "Limpando a sujeira!"
cd
rm -rf "$TEMP_DIR"

# TODO: Traduzir para o inglês.
# TODO: Decobrir qual o shell e colocar no arquivo de Configuração

# # Função para adicionar sem duplicar
# add_to_path() {
#     if [[ -d "$1" ]] && [[ ":$PATH:" != *":$1:"* ]]; then
#         export PATH="$1:$PATH"
#     fi
# }
#
# # Uso:
# add_to_path "$HOME/.local/bin"
# add_to_path "/usr/local/go/bin"
