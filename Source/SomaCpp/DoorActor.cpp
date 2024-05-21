// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(RootComponent);

	

}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();

	if(CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this,&ADoorActor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
	
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);
}

void ADoorActor::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact with Door"));
	if(bIsOpenDoor)
	{
		if(bIsDoorClosed)
		{
			Timeline.Play();
		}else
		{
			Timeline.Reverse();
		}
		bIsDoorClosed = !bIsDoorClosed;
		
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't Open this one"));
	}
	
}

void ADoorActor::OpenDoor(float Value)
{
	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);
	Door->SetRelativeRotation(Rot);
}



