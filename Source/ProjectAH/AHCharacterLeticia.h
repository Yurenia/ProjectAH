// Copyright Fox Tales Studio. All right reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AHCharacterLeticia.generated.h"

UCLASS()
class PROJECTAH_API AAHCharacterLeticia : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAHCharacterLeticia();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//캡슐 컴포넌트의 사이즈

	float CharacterCapsuleSizeRadius;
	float CharacterCapsuleSizeHalfHeight;

	/*	캐릭터 움직임 */

	bool isSprint; // 캐릭터가 스프린트 상태인가?
	bool isWalkSlow; // 캐릭터가 천천히 걷는 상태인가? 

	UPROPERTY(EditAnywhere, Category = "Character Sprint")
	float DefaultWalkSpeed; // 캐릭터의 걷기 속도 기본값
	UPROPERTY(EditAnywhere, Category = "Character Sprint")
	float SprintSpeedRate; // 스프린트 속도 비율
	
	UPROPERTY(EditAnywhere, Category = "Character Sprint")
	float WalkSlowSpeedRate; // 느리게 걷기 속도 비율

	UCharacterMovementComponent* PlayerMovementComponent;

	UFUNCTION(BlueprintInternalUseOnly)
	void MoveForward(float Value);

	UFUNCTION(BlueprintInternalUseOnly)
	void MoveRight(float Value);

	UFUNCTION(BlueprintInternalUseOnly)
	void StartSprint();

	UFUNCTION(BlueprintInternalUseOnly)
	void StopSprint();
	
	UFUNCTION(BlueprintInternalUseOnly)
	void StartWalkSlow();

	UFUNCTION(BlueprintInternalUseOnly)
	void StopWalkSlow();

	UFUNCTION(BlueprintImplementableEvent, Category="Character Interaction")
	void InteractEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "Character Interaction")
	void CallPauseMenuEvent();
};
