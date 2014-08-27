.class Lcom/example/smali/MainActivity$2;
.super Ljava/lang/Object;
.source "MainActivity.java"

# interfaces
.implements Landroid/view/View$OnClickListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/example/smali/MainActivity;->onCreate(Landroid/os/Bundle;)V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Lcom/example/smali/MainActivity;


# direct methods
.method constructor <init>(Lcom/example/smali/MainActivity;)V
    .locals 0
    .parameter

    .prologue
    .line 1
    iput-object p1, p0, Lcom/example/smali/MainActivity$2;->this$0:Lcom/example/smali/MainActivity;

    .line 39
    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onClick(Landroid/view/View;)V
    .locals 2
    .parameter "arg0"

    .prologue
    .line 44
    iget-object v0, p0, Lcom/example/smali/MainActivity$2;->this$0:Lcom/example/smali/MainActivity;

    iget-object v0, v0, Lcom/example/smali/MainActivity;->tv:Landroid/widget/TextView;

    #const-string v1, "jiu bu"
	const-string v1, "modify  by smali"

    invoke-virtual {v0, v1}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 45
    return-void
.end method
