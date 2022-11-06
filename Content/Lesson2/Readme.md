

- Create actor/component from constructor :


static ConstructorHelpers::FObjectFinder<UStaticMesh> ButtonSupportMeshFinder(
    TEXT("StaticMesh'/PixoCore/Meshes/InteractableObjects/SM_ButtonSupport.SM_ButtonSupport'"));
  UStaticMesh* ButtonSupportMesh = ButtonSupportMeshFinder.Object;
  