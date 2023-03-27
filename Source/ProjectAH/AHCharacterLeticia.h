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
	
	//ĸ�� ������Ʈ�� ������

	float CharacterCapsuleSizeRadius;
	float CharacterCapsuleSizeHalfHeight;

	/*	ĳ���� ������ */

	bool isSprint; // ĳ���Ͱ� ������Ʈ �����ΰ�?
	bool isWalkSlow; // ĳ���Ͱ� õõ�� �ȴ� �����ΰ�? 
	float DefaultWalkSpeed; // ĳ������ �ȱ� �ӵ� �⺻��

	UPROPERTY(EditAnywhere, Category = "Funtion Test")
	float SprintSpeedRate; // ������Ʈ �ӵ� ����
	
	UPROPERTY(EditAnywhere, Category = "Funtion Test")
	float WalkSlowSpeedRate; // ������ �ȱ� �ӵ� ����

	UCharacterMovementComponent* PlayerMovementComponent;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
	void StartSprint();

	UFUNCTION(BlueprintCallable)
	void StopSprint();
	
	UFUNCTION(BlueprintCallable)
	void StartWalkSlow();

	UFUNCTION(BlueprintCallable)
	void StopWalkSlow();

	UFUNCTION(BlueprintImplementableEvent, Category="Character Interaction")
	void Interact();

	UFUNCTION(BlueprintImplementableEvent, Category = "Character Interaction")
	void Pasue();
};
