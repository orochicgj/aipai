.class public Lcom/example/smali/MainActivity;
.super Landroid/app/Activity;
.source "MainActivity.java"


# annotations
.annotation system Ldalvik/annotation/MemberClasses;
    value = {
        Lcom/example/smali/MainActivity$PlaceholderFragment;
    }
.end annotation


# instance fields
.field btn1:Landroid/widget/Button;

.field btn2:Landroid/widget/Button;

.field str1:Ljava/lang/String;

.field tv:Landroid/widget/TextView;


# direct methods
.method public constructor <init>()V
    .locals 1

    .prologue
    .line 14
    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    .line 18
    const-string v0, "quan jiu"

    iput-object v0, p0, Lcom/example/smali/MainActivity;->str1:Ljava/lang/String;

    .line 14
    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 4
    .parameter "savedInstanceState"

    .prologue
    .line 22
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    .line 23
    const/high16 v1, 0x7f03

    invoke-virtual {p0, v1}, Lcom/example/smali/MainActivity;->setContentView(I)V

    .line 25
    const v1, 0x7f080002

    invoke-virtual {p0, v1}, Lcom/example/smali/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/Button;

    iput-object v1, p0, Lcom/example/smali/MainActivity;->btn1:Landroid/widget/Button;

    .line 26
    const v1, 0x7f080003

    invoke-virtual {p0, v1}, Lcom/example/smali/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/Button;

    iput-object v1, p0, Lcom/example/smali/MainActivity;->btn2:Landroid/widget/Button;

    .line 27
    const v1, 0x7f080001

    invoke-virtual {p0, v1}, Lcom/example/smali/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/TextView;

    iput-object v1, p0, Lcom/example/smali/MainActivity;->tv:Landroid/widget/TextView;

    .line 28
    const-string v0, "jiu bu"

    .line 30
    .local v0, str2:Ljava/lang/String;
    iget-object v1, p0, Lcom/example/smali/MainActivity;->btn1:Landroid/widget/Button;

    new-instance v2, Lcom/example/smali/MainActivity$1;

    invoke-direct {v2, p0}, Lcom/example/smali/MainActivity$1;-><init>(Lcom/example/smali/MainActivity;)V

    invoke-virtual {v1, v2}, Landroid/widget/Button;->setOnClickListener(Landroid/view/View$OnClickListener;)V

    .line 39
    iget-object v1, p0, Lcom/example/smali/MainActivity;->btn2:Landroid/widget/Button;

    new-instance v2, Lcom/example/smali/MainActivity$2;

    invoke-direct {v2, p0}, Lcom/example/smali/MainActivity$2;-><init>(Lcom/example/smali/MainActivity;)V

    invoke-virtual {v1, v2}, Landroid/widget/Button;->setOnClickListener(Landroid/view/View$OnClickListener;)V

    .line 48
    if-nez p1, :cond_0

    .line 49
    invoke-virtual {p0}, Lcom/example/smali/MainActivity;->getFragmentManager()Landroid/app/FragmentManager;

    move-result-object v1

    invoke-virtual {v1}, Landroid/app/FragmentManager;->beginTransaction()Landroid/app/FragmentTransaction;

    move-result-object v1

    .line 50
    const/high16 v2, 0x7f08

    new-instance v3, Lcom/example/smali/MainActivity$PlaceholderFragment;

    invoke-direct {v3}, Lcom/example/smali/MainActivity$PlaceholderFragment;-><init>()V

    invoke-virtual {v1, v2, v3}, Landroid/app/FragmentTransaction;->add(ILandroid/app/Fragment;)Landroid/app/FragmentTransaction;

    move-result-object v1

    invoke-virtual {v1}, Landroid/app/FragmentTransaction;->commit()I

    .line 52
    :cond_0
    return-void
.end method

.method public onCreateOptionsMenu(Landroid/view/Menu;)Z
    .locals 2
    .parameter "menu"

    .prologue
    .line 58
    invoke-virtual {p0}, Lcom/example/smali/MainActivity;->getMenuInflater()Landroid/view/MenuInflater;

    move-result-object v0

    const/high16 v1, 0x7f07

    invoke-virtual {v0, v1, p1}, Landroid/view/MenuInflater;->inflate(ILandroid/view/Menu;)V

    .line 59
    const/4 v0, 0x1

    return v0
.end method

.method public onOptionsItemSelected(Landroid/view/MenuItem;)Z
    .locals 2
    .parameter "item"

    .prologue
    .line 67
    invoke-interface {p1}, Landroid/view/MenuItem;->getItemId()I

    move-result v0

    .line 68
    .local v0, id:I
    const v1, 0x7f080004

    if-ne v0, v1, :cond_0

    .line 69
    const/4 v1, 0x1

    .line 71
    :goto_0
    return v1

    :cond_0
    invoke-super {p0, p1}, Landroid/app/Activity;->onOptionsItemSelected(Landroid/view/MenuItem;)Z

    move-result v1

    goto :goto_0
.end method
