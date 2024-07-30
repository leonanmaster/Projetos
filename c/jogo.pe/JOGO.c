#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_POTIONS 3

 typedef struct 
{
    char nome[50];
    int energia;
    int habilidade;
    int sorte;
    char jornada[50];
    int energiaMax;
    int num_pocoes;
    
} PERSONAGEM;

typedef struct 
{
    int energia;
    int habilidade;
    int sorte;
    int morto;

} INIMIGO;

void Save(PERSONAGEM *jogador);
void IniciarNovoJogo(PERSONAGEM *jogador);
void ContinuarJogo(PERSONAGEM *jogador);
void ListarIntegrantes();
void GeraRand(PERSONAGEM *jogador);
int DistPont(int pont, PERSONAGEM *jogador);
void LevelUp(int pont, PERSONAGEM *jogador);
void Apresentacao();
void Combate_final(PERSONAGEM *jogador, INIMIGO *oponente);
void Combate(PERSONAGEM *jogador, INIMIGO *oponente);
void Causadano(INIMIGO *oponente, PERSONAGEM *jogador);
void Morte(PERSONAGEM *jogador);
int Testasorte(PERSONAGEM *jogador);
int LerHist(PERSONAGEM *jogador);
int VerBat(PERSONAGEM *jogador);
void adicionarPocao(PERSONAGEM *jogador);
void UsarPocao(PERSONAGEM *jogador);
void CausadanoI(INIMIGO *oponente, PERSONAGEM *jogador);
int VerRest(PERSONAGEM *jogador);
int VerB(PERSONAGEM *jogador);
void GO(PERSONAGEM *jogador);

int main()
{

    PERSONAGEM jogador;
    
    int opcao;

    int resposta = 1;

    while(resposta == 1) {
        printf("=================================\n");
        printf("            MENU INICIAL         \n");
        printf("=================================\n");
        printf("1.Iniciar Jogo\n");
        printf("2.Continuar Jogo\n");
        printf("3.Apresentacao do Jogo\n");
        printf("4.Listar Integrantes do Grupo\n");
        printf("5.Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d" , &opcao);

        switch(opcao){
            case 1:
                IniciarNovoJogo(&jogador);
                resposta = 2;    
                break; 
            case 2:
                ContinuarJogo(&jogador);
                resposta = 2;    
                break;
            case 3:
                Apresentacao();
                break;
            case 4:
                ListarIntegrantes();
                break;
            case 5:
                printf("Saindo do jogo...\n");
                exit(0);
            default:
                printf("Opcao Invalida! Tente Novamente.\n");
                main();

        }


        
    }
    LerHist(&jogador);
    return 0;
}

void Apresentacao()
{
    system("cls");
    FILE* f;
    char ln[200];
    f = fopen("apresenta.txt","r");

    if(f == NULL){
        perror("apresenta.txt");
    }
    while(fgets(ln, sizeof(ln), f)){
        printf("%s", ln);
    }
    printf("\n");
    main();
}

void IniciarNovoJogo(PERSONAGEM *jogador)
{
    system("cls");
    printf("==========================================\n");
    printf("            CRIACAO DE PERSONAGEM         \n");
    printf("==========================================\n");
    printf("Escolha o seu nome: ");
    
    getchar();
    fgets(jogador->nome, 50, stdin);// pega o nome do jogador
    jogador->nome[strcspn(jogador->nome, "\n")] = '\0';
    //scanf("%s", jogador->nome);

    int opc;

    printf("Como voce quer distribuir seus pontos? \n");
    printf("1. Aleatoriamente (recomendado).\n");
    printf("2. Distribuindo meus pontos.\n");
    
    scanf("%d", &opc);

    switch(opc){
        case 1:
            GeraRand(jogador);
            break;
        case 2:
            DistPont(34, jogador);
            break;
        default:
            printf("Opcao Invalida! Tente Novamente.\n");
            break;
    }
    
    //Combate(jogador);
    strcpy(jogador->jornada, "capitulo1.txt");
    jogador->energiaMax = jogador->energia;
    jogador->num_pocoes = 0;
    
    Save(jogador);

}

void ContinuarJogo(PERSONAGEM *jogador)
{
    printf("Continuando um jogo gravado...\n");

    FILE *save1 = fopen("saves.dat", "rb");
    if (save1 == NULL) {
        printf("\nArquivo nao pode ser aberto\n");
        return;
    }
    
    size_t read = fread(jogador, sizeof(PERSONAGEM), 1, save1); 
    if (read != 1){
        printf("Erro ao carregar o personagem\n");
        
    } else {
        printf("\nSave carregado com sucesso\n");

        printf("Nome: %s\n", jogador->nome);
        printf("Habilidade: %d\n", jogador->habilidade);
        printf("Energia: %d\n", jogador->energia);
        printf("Sorte: %d\n\n\n", jogador->sorte);
    }

    fclose(save1);
}

void ListarIntegrantes()
{
    system("cls");
    printf("========== INTEGRANTES: ==========\n");
    printf("Leonan Louvem; \nRafael Goulart; \nLucas Santiago. \n");
    main();
}

void Save(PERSONAGEM *jogador)
{
    FILE* save = fopen("saves.dat", "wb");
    if (save == NULL) {
        printf("\nArquivo nao pode ser aberto\n");
        return;
    }
    
    size_t written = fwrite(jogador, sizeof(PERSONAGEM), 1, save);
    if (written != 1) {
        printf("Erro ao salvar o personagem\n");
    } else {
        printf("\nPersonagem salvo com sucesso\n");
    }

    
    fclose(save);
}

void GeraRand(PERSONAGEM *jogador)
{
    srand(time(NULL));
    jogador->habilidade = (rand() % 7) + 6;
    while (jogador->habilidade == 6) {
        jogador->habilidade = (rand() % 7) + 6;
    }
    jogador->energia = (rand() % 13) + 12;
    while (jogador->energia == 12) {
        jogador->energia = (rand() % 13) + 12;
    }
    jogador->sorte = (rand() % 7) + 6;
    while (jogador->sorte == 6) {
        jogador->sorte = (rand() % 7) + 6;
    }
    printf("Seus Atributos: \n");
    printf("Habilidade: %d \n", jogador->habilidade);
    printf("Energia: %d \n", jogador->energia);
    printf("Sorte: %d \n", jogador->sorte);

}

int DistPont(int pont, PERSONAGEM *jogador)
{
    jogador->energia = 0;
    jogador->sorte = 0;
    jogador->habilidade = 0;
    int somatorio_de_pontos = 0;
    printf("Distribua a pontuacao do seu personagem entre Habilidade, Energia e Sorte\nvoce tem %d pontos :", pont);
    printf("\nHabilidade: ");
    scanf("%d", &jogador->habilidade);
    somatorio_de_pontos = jogador->habilidade;
    while (somatorio_de_pontos > pont) {
        printf("limite de pontos atingido, digite novamente: ");
        scanf("%d", &jogador->habilidade);
        somatorio_de_pontos = jogador->habilidade;
    }
    if ((pont - somatorio_de_pontos) == 0) {
         printf("======================================================\n");
        printf("Visao geral: Habilidade: %d | Energia: %d | Sorte: %d\n",  jogador->habilidade, jogador->energia, jogador->sorte);
        printf("======================================================\n");
        return 0;
    }
    printf("------restam %d pontos------\n", pont - somatorio_de_pontos);

    printf("Energia: ");
    scanf("%d", &jogador->energia);
    somatorio_de_pontos += jogador->energia;
    while (somatorio_de_pontos > pont) {
        printf("limite de pontos atingido, digite novamente: ");
        scanf("%d", &jogador->energia);
        somatorio_de_pontos = jogador->habilidade + jogador->energia;
    }
    if ((pont - somatorio_de_pontos) == 0) {
         printf("======================================================\n");
    printf("Visao geral: Habilidade: %d | Energia: %d | Sorte: %d\n",  jogador->habilidade, jogador->energia, jogador->sorte);
    printf("======================================================\n");
        return 0;
    }
    printf("------restam %d pontos------\n", pont - somatorio_de_pontos);

    printf("Sorte: ");
    scanf("%d", &jogador->sorte);
    somatorio_de_pontos += jogador->sorte;
    while (somatorio_de_pontos > pont) {
        printf("limite de pontos atingido, digite novamente: ");
        scanf("%d", &jogador->sorte);
        somatorio_de_pontos = jogador->sorte + jogador->habilidade + jogador->energia;
    }
    printf("======================================================\n");
    printf("Visao geral: Habilidade: %d | Energia: %d | Sorte: %d\n",  jogador->habilidade, jogador->energia, jogador->sorte);
    printf("======================================================\n");
    
}

void Combate(PERSONAGEM *jogador, INIMIGO *oponente)
{
    
    int op;
    int fuga;
    int continuar = 1;
    srand(time(NULL));
    int primeiro = rand() % 2;
    
    while (jogador->energia > 0 && oponente->energia > 0 && continuar){
        
        if(primeiro % 2 == 0){
            printf("--------------------------------------\n");
            printf("Eu ataco\n");
            CausadanoI(oponente,jogador);
            if(oponente->energia <= 0){
                oponente->energia = 0;
                oponente->morto = 1;
                printf("Inimigo morto \n");
                break;
            }
            printf("O inimigo ficou com HP de %d\n", oponente->energia);
            printf("--------------------------------------\n");
            
            primeiro++;
            
        }else{
            printf("--------------------------------------\n");
            printf("Inimigo ataca\n");
            Causadano(oponente,jogador);
            
            Morte(jogador);

        
            printf("Fiquei com HP de %d\n", jogador->energia);
            printf("--------------------------------------\n");
           
            printf("1.Atacar\n");
            printf("2.Fugir\n");
            printf("3.Pocao\n");
            scanf("%d", &op);

            switch(op){
                case 1:
                    primeiro++;
                    break;
                case 2:
                    fuga = Testasorte(jogador);
                    printf("Rolamento de sorte: %d\n", fuga);
                    if (fuga == 1){
                        jogador->energia -= 2;
                        printf("Fuga realizada com sucesso!!! (-2 de Energia) \n");
                        printf("Energia: %d \n", jogador->energia);
                        if(strcmp(jogador->jornada,"capitulo 4A.txt") == 0) {
                            strcpy(jogador->jornada, "capitulo 4B.txt");
                        }
                        else if(strcmp(jogador->jornada,"capitulo 7A.txt") == 0) {
                            strcpy(jogador->jornada, "capitulo 7B.txt");
                        }
                        else if(strcmp(jogador->jornada,"capitulo 10A.txt") == 0) {
                            strcpy(jogador->jornada, "capitulo 10B.txt");
                            
                        }
                        continuar = 0;// sai do loop
                    }else{
                        jogador->energia = 0;
                        system("cls");
                        printf("Ao tentar correr seu inimigo te neutralizou! \n");
                        GO(jogador);
                    }
                    break;
                case 3:
                    UsarPocao(jogador);
                    break;


            }
        }   
    }
}

void Combate_final(PERSONAGEM *jogador, INIMIGO *oponente)
{
    
    int op;
    int continuar = 1;
    srand(time(NULL));
    int primeiro = rand() % 2;
    
    while (jogador->energia > 0 && oponente->energia > 0 && continuar){
        
        if(primeiro % 2 == 0){
            printf("--------------------------------------\n");
            printf("Eu ataco\n");
            CausadanoI(oponente,jogador);
            if(oponente->energia <= 0){
                oponente->energia = 0;
                oponente->morto = 1;
                printf("Inimigo morto \n");
                break;
            }
            printf("O inimigo ficou com HP de %d\n", oponente->energia);
            printf("--------------------------------------\n");
            
            primeiro++;
            
        }else{
            printf("--------------------------------------\n");
            printf("Inimigo ataca\n");
            Causadano(oponente,jogador);
            
            Morte(jogador);

        
            printf("Fiquei com HP de %d\n", jogador->energia);
            printf("--------------------------------------\n");
           
            printf("1.Atacar\n");
            printf("2.Pocao\n");
            scanf("%d", &op);

            switch(op){
                case 1:
                    primeiro++;
                    break;
                case 2:
                    UsarPocao(jogador);
                    break;
            }
        }   
    }
}

void Causadano(INIMIGO *oponente, PERSONAGEM *jogador)
{
    srand(time(NULL));
    int dn = (rand() % (oponente->habilidade - (oponente->habilidade-2) + 1)) + (oponente->habilidade-2);
    while(dn < 0) {
        dn = (rand() % (oponente->habilidade - (oponente->habilidade-2) + 1)) + (oponente->habilidade-2);
    }
    jogador->energia = jogador->energia - dn;
    if(dn == oponente->habilidade){
        printf("CRiTICO!!!\n");
        printf("dano: %d\n", dn);
    }else{
        printf("dano: %d\n", dn);
    }
}

void CausadanoI(INIMIGO *oponente, PERSONAGEM *jogador)
{
    srand(time(NULL));
    int dn = (rand() % (jogador->habilidade - (jogador->habilidade-2) + 1)) + (jogador->habilidade-2);
    while(dn < 0) {
        dn = (rand() % (jogador->habilidade - (jogador->habilidade-2) + 1)) + (jogador->habilidade-2);
    }
    oponente->energia = oponente->energia - dn;
    if(dn == jogador->habilidade){
        printf("CRiTICO!!!\n");
        printf("dano: %d\n", dn);
    }else{
        printf("dano: %d\n", dn);
    }
}

int Testasorte(PERSONAGEM *jogador)
{
    int roll;
    
    srand(time(NULL));
    roll = (rand() % 7) + 6;
    while (roll == 6) {
        roll = (rand() % 7) + 6;
    }
    
    if (roll <= jogador->sorte){
        return 1;
    }else{
        return 0;
    }
}

void Morte(PERSONAGEM *jogador)
{
    if (jogador->energia <= 0){
        jogador->energia = 0;
        printf("Seu inimigo te neutralizou! \n");
        GO(jogador);
    }
}

int LerHist(PERSONAGEM* jogador)
{
    FILE* arquivo;

    while(1) {
         VerBat(jogador);
        arquivo = fopen(jogador->jornada, "r");

        if (arquivo == NULL) {
            
            printf("erro");
            return 0;
        }
        
        VerRest(jogador);
        VerB(jogador);

        char print[256];

        while(fgets(print, sizeof(print), arquivo)) {
            
            printf("%s", print);
        }
        int choice;
       if (strcmp(jogador->jornada, "capitulo 13A.txt") == 0 || strcmp(jogador->jornada, "capitulo 13B.txt") == 0 || strcmp(jogador->jornada, "capitulo 13C.txt") == 0) {
        exit(0);
       }
     
        
        printf("\nVer seus status: (Digite 3)\n");
        printf("\nSair: (Digite: 4)\n");
        
        scanf("%d", &choice);
       
        
        
        if (choice == 1) { 
            if (strcmp(jogador->jornada,"capitulo1.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 2A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 2A.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 3A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 2B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 3C.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 3C.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 4A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 3A.txt") == 0 || strcmp(jogador->jornada,"capitulo 3B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 4A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 4A.txt") == 0 || strcmp(jogador->jornada,"capitulo 4B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 5A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 5A.txt") == 0 || strcmp(jogador->jornada,"capitulo 5B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 6A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 6A.txt") == 0 || strcmp(jogador->jornada,"capitulo 6B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 7A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 7A.txt") == 0 || strcmp(jogador->jornada,"capitulo 7B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 8A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 8A.txt") == 0 || strcmp(jogador->jornada,"capitulo 8B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 9A.txt");
               
            }
            else if (strcmp(jogador->jornada,"capitulo 9A.txt") == 0 || strcmp(jogador->jornada,"capitulo 9B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 10A.txt");
                
            }
            else if (strcmp(jogador->jornada,"capitulo 10A.txt") == 0 || strcmp(jogador->jornada,"capitulo 10B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 11A.txt");
                
            }
            else if (strcmp(jogador->jornada,"capitulo 11A.txt") == 0 || strcmp(jogador->jornada,"capitulo 11B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 12A.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 12A.txt") == 0 || strcmp(jogador->jornada,"capitulo 12B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 13A.txt");
                
            }
            system("cls");
        }
        else if (choice == 2) { 
            if (strcmp(jogador->jornada,"capitulo1.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 2B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 2A.txt") == 0 || strcmp(jogador->jornada,"capitulo 2B.txt") == 0 ){
                strcpy(jogador->jornada,"capitulo 3B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 3A.txt") == 0 || strcmp(jogador->jornada,"capitulo 3B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 4B.txt");
                
            }
            else if (strcmp(jogador->jornada,"capitulo 3C.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 4B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 4A.txt") == 0 || strcmp(jogador->jornada,"capitulo 4B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 5B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 5A.txt") == 0 || strcmp(jogador->jornada,"capitulo 5B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 6B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 6A.txt") == 0 || strcmp(jogador->jornada,"capitulo 6B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 7B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 7A.txt") == 0 || strcmp(jogador->jornada,"capitulo 7B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 8B.txt");
            }
            else if (strcmp(jogador->jornada,"capitulo 8A.txt") == 0 || strcmp(jogador->jornada,"capitulo 8B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 9B.txt");
               
            }
            else if (strcmp(jogador->jornada,"capitulo 9A.txt") == 0 || strcmp(jogador->jornada,"capitulo 9B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 10B.txt");
                
            }
            else if (strcmp(jogador->jornada,"capitulo 10A.txt") == 0 || strcmp(jogador->jornada,"capitulo 10B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 11B.txt");
                
            }
            else if (strcmp(jogador->jornada,"capitulo 11A.txt") == 0 || strcmp(jogador->jornada,"capitulo 11B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 12B.txt");
            }

            else if (strcmp(jogador->jornada,"capitulo 12A.txt") == 0) {
                if (jogador->habilidade >= 20) {
                    strcpy(jogador->jornada,"capitulo 13B.txt");
                }
                
                else {
                    printf("sua habilidade e:%d\n", jogador->habilidade);
                    printf("voce nao possui habilidade o suficiente\n");
                }
                
            }
            else if (strcmp(jogador->jornada,"capitulo 12B.txt") == 0) {
                strcpy(jogador->jornada,"capitulo 13C.txt");
                
            }
            system("cls");
        }
        else if (choice == 3) {
            system("cls");
            printf("======================================================\n");
            printf("Visao geral: Habilidade: %d | Energia: %d/%d | Sorte: %d | Pocoes: %d/3\n",  jogador->habilidade, jogador->energia, jogador->energiaMax, jogador->sorte, jogador->num_pocoes);
            printf("======================================================\n");
        }
        else if (choice == 4) {
            exit(0);
        }
        
        Save(jogador);
        for (int i = 0; i<3; i++) {
            printf("\n");
        }
        //system("cls");
        printf("====================================================\n");
     }
     
}

int VerBat(PERSONAGEM *jogador)
{

    if (strcmp(jogador->jornada, "capitulo 4A.txt") == 0) {
        INIMIGO SSib;
        SSib.energia = 15;
        SSib.habilidade = 3;
        SSib.sorte = 3;
        SSib.morto = 0;
        Combate(jogador, &SSib);
        
        if(SSib.morto == 1){
            LevelUp(1, jogador);
            adicionarPocao(jogador);
            adicionarPocao(jogador);
        } 
    }
    else if (strcmp(jogador->jornada, "capitulo 7A.txt") == 0) {
        INIMIGO IaLider;
        IaLider.energia = 18;
        IaLider.habilidade = 5;
        IaLider.sorte = 5;
        IaLider.morto = 0;
        Combate(jogador, &IaLider);  

        if(IaLider.morto == 1){
            LevelUp(2, jogador);
            adicionarPocao(jogador);
            adicionarPocao(jogador);
        } 
    }
    else if (strcmp(jogador->jornada, "capitulo 10A.txt") == 0) {
        INIMIGO ChefeSeg;
        ChefeSeg.energia = 20;
        ChefeSeg.habilidade = 8;
        ChefeSeg.sorte = 8;
        ChefeSeg.morto = 0;
        Combate(jogador, &ChefeSeg);  

        if(ChefeSeg.morto == 1){
            LevelUp(2, jogador);
            adicionarPocao(jogador);
            adicionarPocao(jogador);
        }  

    }
    else if (strcmp(jogador->jornada, "capitulo 13A.txt") == 0) {
        INIMIGO BossSup;
        BossSup.energia = 25;
        BossSup.habilidade = 10;
        BossSup.sorte = 10;
        BossSup.morto = 0;
        Combate_final(jogador, &BossSup);  
    }


    return 0;
}

void adicionarPocao(PERSONAGEM *jogador) 
{

    if (jogador->num_pocoes < MAX_POTIONS) {
        jogador->num_pocoes++;
        printf("Pocao adicionada ao inventario!\n");
    } 
    else {
        printf("Inventario de pocoes esta cheio!\n");
    }
}

void UsarPocao(PERSONAGEM* jogador) 
{
    if (jogador->num_pocoes > 0) {
       if ((jogador->energia + (jogador->energiaMax*0,30)) > jogador->energiaMax) {
        printf("usou a pocao e curou %d de energia.\n", (jogador->energiaMax - jogador->energia));
        jogador->energia = jogador->energiaMax;
        
       }
       else {
        jogador->energia += (jogador->energiaMax*0,30);
        printf("usou a pocao e curou %d de energia.\n", (jogador->energiaMax*0,30));
       }
        
        jogador->num_pocoes--;
        printf("Numero de pocoes restantes: %d\n", jogador->num_pocoes);
    }

    else {
        printf("voce nao possui pocoes de cura!\n");
    }
}

void LevelUp(int pont, PERSONAGEM *jogador)
{
    int ch;
    
    while(pont > 0){
        
        printf("Voce tem %d ponto(s) para distibuir! \n", pont);
        printf("Mais um para Energia(1), Habilidade(2) ou Sorte(3)? \n");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                jogador->energiaMax++;
                pont--;
                break;
            case 2:
                jogador->habilidade++;
                pont--;
                break;
            case 3:
                jogador->sorte++;
                pont--;
                break;
            default:
                printf("Opcao Invalida! Tente Novamente.\n");
                break;
        }
    } 

    printf("======================================================\n");
    printf("Visao geral: Habilidade: %d | Energia: %d/%d | Sorte: %d\n",  jogador->habilidade, jogador->energia, jogador->energiaMax, jogador->sorte);
    printf("======================================================\n");

}

int VerRest(PERSONAGEM *jogador)
{
    if (strcmp(jogador->jornada, "capitulo 5A.txt") == 0 || strcmp(jogador->jornada, "capitulo 11A.txt") == 0) {
        jogador->energia = jogador->energiaMax;
        printf("Energia restaurada!!!\n");
        printf("======================================================\n");
        printf("Visao geral: Habilidade: %d | Energia: %d/%d | Sorte: %d\n",  jogador->habilidade, jogador->energia, jogador->energiaMax, jogador->sorte);
        printf("======================================================\n");
    }
    return 0;
}

int VerB(PERSONAGEM *jogador)
{
    if (strcmp(jogador->jornada, "capitulo 5B.txt") == 0 || strcmp(jogador->jornada, "capitulo 11B.txt") == 0) {
        jogador->habilidade++;
        printf("Voce ganhou um ponto em Habilidade\n");
        printf("======================================================\n");
        printf("Visao geral: Habilidade: %d | Energia: %d/%d | Sorte: %d\n",  jogador->habilidade, jogador->energia, jogador->energiaMax, jogador->sorte);
        printf("======================================================\n");
    }
    return 0;
}

void GO(PERSONAGEM *jogador)
{
    int esc;
    
    printf("==========================================\n");
    printf("                 GAME OVER                \n");
    printf("==========================================\n");
    printf("1.Tentar novamente\n");
    printf("2.Menu principal\n");
    printf("3.Sair do jogo\n");

    scanf("%d", &esc);

    switch(esc){
        case 1:
            ContinuarJogo(jogador);
            break;
        case 2:
            main();
            break;
        case 3: 
            printf("Saindo....");
            exit(0);
        default:
            printf("Opcao Invalida! Tente Novamente.\n");
    }
}