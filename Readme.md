# Unreal Engine Course 

1) General most used API : 

```c++
    TSubclassOf<UObject> Class;
    UObject* Object = NewObject<UObject>(this, Class);

    UGameInstance* GameInstance = GetWorld()->GetGameInstance<UGameInstance>();
    UGameInstance* GameInstance2 = this->GetGameInstance();

    AGameMode* GameMode = GetWorld()->GetAuthGameMode<AGameMode>();
    // GameMode->InitGame()
    // GameMode->PreLogin()
    // GameMode->PostLogin()
    // GameMode->SpawnDefaultPawnAtTransform()
    // GameMode->Logout()

    AGameState* GameState = GetWorld()->GetGameState<AGameState>();
    AGameState* GameState2 = GameMode->GetGameState<AGameState>();
    float Seconds = GameState->GetServerWorldTimeSeconds();
    TArray<APlayerState*> Players = GameState->PlayerArray;
    bool IsBegun = GameState->HasBegunPlay();

    TSubclassOf<AActor> ClassActor;
    FVector Location;
    FRotator Rotation;
    AActor* Actor = GetWorld()->SpawnActor<AActor>(ClassActor, Location, Rotation);
    // Actor->BeginPlay()
    // Actor->Tick()
    // Actor->EndPlay()
    // Actor->GetActorLocation() | GetActorRotation() | GetActorScale()
    // Actor->SetActorLocation() | SetActorRotation() | SetActorScale()
    // Actor->GetComponentLocation() | GetComponentRotation() | GetComponentScale()
    // Actor->SetComponentLocation() | SetComponentRotation() | SetComponentScale()

    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    SceneComponent->SetupAttachment(RootComponent);

    USceneComponent* SceneComponent2 = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    SceneComponent->SetupAttachment(SceneComponent);

    FConstPlayerControllerIterator PlayerControllerIterator = GetWorld()->GetPlayerControllerIterator();
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    AController* Controller2 = this->GetController();

    APawn* Pawn = PlayerController->GetPawn();
    ACharacter* Character = PlayerController->GetCharacter();
    FConstPawnIterator PawnIterator = GetWorld()->GetPawnIterator();
```


2)  If Rider/VS can't generate solution - add to targets

```c#
bOverrideBuildEnvironment = true;
AdditionalCompilerArguments = "-Wno-unused-but-set-variable";
```

3) For casting - always use 
```c++
static_cast<FLinearColor>(vectorColor) 
```


4) Unreal Common Data Types - see here https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/IntroductionToCPP/ :

```c++
FString string = TEXT("custom text")

FVector 

FRotator 

FColor

TArray<AActor*> ActorArray = GetActorArrayFromSomewhere();

TMap<FIntPoint, FPiece> Data;
```


5) Unreal Class Architecture - https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/
