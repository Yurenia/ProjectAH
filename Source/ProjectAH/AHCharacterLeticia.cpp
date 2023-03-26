// Copyright Fox Tales Studio. All right reserved.


#include "AHCharacterLeticia.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AAHCharacterLeticia::AAHCharacterLeticia()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	

	CharacterCapsuleSizeRadius = 40.0f;
	CharacterCapsuleSizeHalfHeight = 85.0f;
	SprintSpeedRate = 1.35f;
	WalkSlowSpeedRate = 0.3f;

	GetCapsuleComponent()->InitCapsuleSize(CharacterCapsuleSizeRadius, CharacterCapsuleSizeHalfHeight);

	isSprint = false;
	isWalkSlow = false;
	PlayerMovementComponent = GetCharacterMovement();
	DefaultWalkSpeed = PlayerMovementComponent->MaxWalkSpeed;

	
}

// Called when the game starts or when spawned
void AAHCharacterLeticia::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAHCharacterLeticia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAHCharacterLeticia::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//check(PlayerInputComponent)

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AAHCharacterLeticia::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AAHCharacterLeticia::MoveRight);

	PlayerInputComponent->BindAxis("Turn Right / Left", this, &AAHCharacterLeticia::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down", this, &AAHCharacterLeticia::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AAHCharacterLeticia::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AAHCharacterLeticia::StopSprint);

	PlayerInputComponent->BindAction("Walk Slow", IE_Pressed, this, &AAHCharacterLeticia::StartWalkSlow);
	PlayerInputComponent->BindAction("Walk Slow", IE_Released, this, &AAHCharacterLeticia::StopWalkSlow);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AAHCharacterLeticia::Interact);


}

void AAHCharacterLeticia::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// 어디가 Forward인지 찾기
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);		
		AddMovementInput(Direction, Value);
	}
}

void AAHCharacterLeticia::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AAHCharacterLeticia::StartSprint()
{
	isSprint = true;
	PlayerMovementComponent->MaxWalkSpeed = DefaultWalkSpeed * SprintSpeedRate;
}

void AAHCharacterLeticia::StopSprint()
{
	isSprint = true;
	PlayerMovementComponent->MaxWalkSpeed = DefaultWalkSpeed;
}

void AAHCharacterLeticia::StartWalkSlow()
{
	isWalkSlow = true;
	PlayerMovementComponent->MaxWalkSpeed = DefaultWalkSpeed * WalkSlowSpeedRate;
}

void AAHCharacterLeticia::StopWalkSlow()
{
	isWalkSlow = false;
	PlayerMovementComponent->MaxWalkSpeed = DefaultWalkSpeed;
}

