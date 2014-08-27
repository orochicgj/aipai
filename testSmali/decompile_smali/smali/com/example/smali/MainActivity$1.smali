.class Lcom/example/smali/MainActivity$1;
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
    iput-object p1, p0, Lcom/example/smali/MainActivity$1;->this$0:Lcom/example/smali/MainActivity;

    .line 30
    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onClick(Landroid/view/View;)V
    .locals 2
    .parameter "arg0"

    .prologue
    .line 35
    iget-object v0, p0, Lcom/example/smali/MainActivity$1;->this$0:Lcom/example/smali/MainActivity;

    iget-object v0, v0, Lcom/example/smali/MainActivity;->tv:Landroid/widget/TextView;

    const v1, 0x7f050000

    invoke-virtual {v0, v1}, Landroid/widget/TextView;->setText(I)V

    .line 36
    return-void
.end method
