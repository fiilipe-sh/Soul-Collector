# Windows Post-Exploitation & Credential Hunting Tool

Uma ferramenta de prova de conceito (PoC) para pós-exploração e auditoria de segurança desenvolvida em C++ para ambientes Windows. Este utilitário consolida diversas técnicas comuns de reconhecimento e busca de credenciais (*credential hunting*) em uma interface de console interativa, projetada para auxiliar times de Red Team e auditores em testes de intrusão autorizados.

> [!WARNING]
> **Aviso de Isenção de Responsabilidade:** Este projeto foi criado estritamente para fins educacionais, de pesquisa e auditoria de segurança autorizada. A execução de shellcodes e a coleta de credenciais só devem ser realizadas em sistemas de sua propriedade ou com permissão explícita por escrito.

---

## Funcionalidades

O utilitário possui um menu interativo que permite ao operador executar módulos específicos de forma sequencial:

* **Mapeamento de Ambiente:** Lista todas as variáveis de ambiente ativas para identificar contextos do sistema.
* **Busca de Credenciais (*Credential Hunting*):**
  * Varre o sistema de arquivos recursivamente em busca de arquivos de configuração de implantação (ex: `unattend.xml`, `sysprep`).
  * Localiza configurações locais de provedores de nuvem (AWS, Azure, GCP) em busca de tokens de acesso ou credenciais salvas.
* **Análise de Registro:** Decodifica e executa consultas ao Registro do Windows (Registry) visando configurações de softwares específicos (VNC, OpenSSH, SNMP) ou buscando strings de senhas expostas.
* **Coleta de Backups do SAM:** Identifica e tenta copiar os arquivos das colmeias SAM e SYSTEM a partir de locais de backup padrão para análise offline de hashes.
* **Injeção de Shellcode (PoC do Exploit-DB):** Demonstração prática de execução de código em memória através das APIs nativas do Windows.

---

## Análise Técnica e Componentes Externos

### Execução de Shellcode (Referência Exploit-DB)
A função `CreateAdministratorDynamic` atua como um *loader* clássico de shellcode em memória. O código utiliza um payload conhecido e documentado publicamente:
* **Autor:** reenz0h (Twitter: [@sektor7net](https://twitter.com/sektor7net))
* **ID de Referência:** [Exploit-DB 51208](https://www.exploit-db.com/shellcodes/51208)

O mecanismo de execução demonstra a manipulação padrão de estados de memória no Windows para fins de estudo de evasão:
1. Aloca memória via `VirtualAlloc` com permissões iniciais de `PAGE_READWRITE`.
2. Copia o array do payload para a região alocada usando `RtlMoveMemory`.
3. Altera as permissões da região para `PAGE_EXECUTE_READ` via `VirtualProtect` para mitigar restrições de DEP (Prevenção de Execução de Dados) antes de disparar a thread com `CreateThread`.

### Ofuscação de Comandos
Comandos que interagem com o sistema operacional ou buscam chaves de registro sensíveis estão codificados em Base64 no código-fonte. Essa abordagem simula táticas reais de evasão de assinaturas estáticas simples durante avaliações de segurança.

---

## Compilação e Pré-requisitos

### Pré-requisitos
* **Ambiente:** Windows 10 / 11 / Server
* **Compilador:** MinGW (`g++`) ou MSVC (Microsoft Visual C++)
* **Bibliotecas:** Bibliotecas padrão do C++ e `windows.h`

### Comando de Compilação (g++)
Para gerar o executável otimizado via terminal:

```bash
g++ -O2 Soul-Collector.cpp -o SoulCollector.exe

```bash
g++ -O2 whitedemon.cpp -o whitedemon.exe
