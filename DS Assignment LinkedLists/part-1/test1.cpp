#include "tree.cpp"


int main()
{
	// bool status = 1;
	// make a tree
	cout<<"Testing Family Tree!!!\n";
	cout<<"Storing members into tree..."<<endl;
	cout<<endl;
	Tree t("Ayesha");
	t.AddChild("Ayesha","Zoha");
	t.AddChild("Ayesha","Rafay");
	t.AddChild("Ayesha","Ayub");
	t.AddChild("Ayesha","Mahnoor");
	t.AddChild("Zoha","Hamza");
	t.AddChild("Zoha","Kinza");
	t.AddChild("Rafay","Ahmed");
	t.AddChild("Ayub","Sara");
	t.AddChild("Ayub","Zoya");
	t.AddChild("Ayub","Bilal");
	t.AddChild("Mahnoor","Ibrahim");
	t.AddChild("Mahnoor","Malik");
	t.AddChild("Hamza","Talha");
	t.AddChild("Ahmed","Ifrah");
	t.AddChild("Ahmed","Hina");
	t.AddChild("Zoya","Amna");
	t.AddChild("Zoya","Tahir");
	t.AddChild("Ibrahim","Usman");
	t.AddChild("Malik","Areej");
	t.AddChild("Talha","Sehar");
	t.AddChild("Talha","Yasir");
	t.AddChild("Hina","Adeena");
	t.AddChild("Hina","Momina");
	t.AddChild("Amna","Sheraz");
	t.AddChild("Usman","Tariq");
	t.AddChild("Usman","Anum");
	t.AddChild("Usman","Adnan");
	t.AddChild("Sehar","Fawad");
	t.AddChild("Sehar","Jawad");
	t.AddChild("Yasir","Ozair");
	t.AddChild("Adeena","Tauqeer");
	t.AddChild("Adeena","Rubina");
	t.AddChild("Momina","Khalid");
	t.AddChild("Sheraz","Afsheen");
	t.AddChild("Anum","Arfa");
	t.AddChild("Anum","Emad");
	t.AddChild("Anum","Noman");
	t.AddChild("Jawad","Anees");
	t.AddChild("Ozair","Taki");
	t.AddChild("Rubina","Asma");
	t.AddChild("Rubina","Neha");
	t.AddChild("Arfa","Umar");
	t.AddChild("Noman","Beenish");
	t.AddChild("Noman","Irfan");
		// cout << t.root->children[1]->children[0]->children[1]->children[1]->children[0]->name<< endl;

	//Testing GetPerson
	cout<<"Testing GetPerson..."<<endl;
	int score=0;

	if(t.GetPerson("Khalid")->name=="Khalid")
	{
		score++;
	}
	if(t.GetPerson("Umar")->name=="Umar")
	{
		score++;
	}
	if(t.GetPerson("Ifrah")->name=="Ifrah")
	{
		score++;
	}
	if(t.GetPerson("Adeena")->name=="Adeena")
	{
		score++;
	}
	if(t.GetPerson("Talha")->name=="Talha")
	{
		score++;	}
	if(t.GetPerson("Tahir")->name=="Tahir")
	{
		score++;
	}
	if(t.GetPerson("Anees")->name=="Anees")
	{
		score++;
	}
	if(t.GetPerson("Ahmed")->name=="Ahmed")
	{
		score++;
	}
	if(t.GetPerson("Momina")->name=="Momina")
	{
		score++;
	}
	if(t.GetPerson("Rubina")->name=="Rubina")
	{
		score++;
	}
	// cout<<"Score: "<<score<<endl;
	if(score==10)
	{
		cout<<"Passed!"<<endl;
	}
	else
	{
		cout << score<< endl;
		cout<<"Failed!"<<endl;
	}
	cout<<endl<<"Testing GetParent..."<<endl;

	cout<<"Your answer: ";
	t.GetParent("Mahnoor");
	cout<<endl;
	cout<<"Correct answer: Ayesha"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetParent("Yasir");
	cout<<endl;
	cout<<"Correct answer: Talha"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetParent("Rubina");
	cout<<endl;
	cout<<"Correct answer: Adeena"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetParent("Usman");
	cout<<endl;
	cout<<"Correct answer: Ibrahim"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetParent("Beenish");
	cout<<endl;
	cout<<"Correct answer: Noman"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetParent("Hina");
	cout<<endl;
	cout<<"Correct answer: Ahmed"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetParent("Tahir");
	cout<<endl;
	cout<<"Correct answer: Zoha"<<endl;
	cout<<endl;
	
	cout<<"Testing GetChildren..."<<endl;
	cout<<"Your answer: ";
	t.GetChildren("Tahir");
	cout<<endl;
	cout<<"Correct answer: Tahir has no children"<<endl;
	cout<<endl;

	cout<<"Your answer: ";
	t.GetChildren("Ayesha");
	cout<<endl;
	cout<<"Correct answer: Zoha, Rafay, Ayub, Mahnoor"<<endl;		
	cout<<endl;

	cout<<"Your answer: ";
	t.GetChildren("Usman");
	cout<<endl;
	cout<<"Correct answer: Tariq, Anum, Adnan"<<endl;	
	cout<<endl;
	
	cout<<"Your answer: ";
	t.GetChildren("Adeena");
	cout<<endl;
	cout<<"Correct answer: Tauqeer, Rubina"<<endl;

	cout<<endl;
	cout<<"Testing GetGeneration..."<<endl;
	score=0;
	if(t.GetGeneration("Ayesha")==1)
	{
		score++;
	}	
	if(t.GetGeneration("Zohaib")==0)
	{
		score++;
	}
	if(t.GetGeneration("Taki")==7)
	{
		score++;
	}
	if(t.GetGeneration("Adnan")==5)
	{
		score++;
	}
	if(t.GetGeneration("Arfa")==6)
	{
		score++;
	}
	if(t.GetGeneration("Hamza")==3)
	{
		score++;
	}
	if(t.GetGeneration("Hina")==4)
	{
		score++;
	}
	if(score==7)
	{
		cout<<"Passed!"<<endl;
	}
	else
	{
		cout<<"Failed!"<<endl;
	}

	cout<<endl;
	cout<<"Testing GenerationCount..."<<endl;

	score=0;

	if(t.GenerationCount(1)==1)
	{
		score++;
	}
	if(t.GenerationCount(2)==4)
	{
		score++;
	}
	if(t.GenerationCount(3)==8)
	{
		score++;
	}
	if(t.GenerationCount(4)==7)
	{
		score++;
	}
	if(t.GenerationCount(5)==8)
	{
		score++;
	}
	if(t.GenerationCount(6)==10)
	{
		score++;
	}
	if(t.GenerationCount(7)==7)
	{
		score++;
	}
	if(t.GenerationCount(11)==0)
	{
		score++;
	}
	if(t.GenerationCount(8)==0)
	{
		score++;
	}
	if(t.GenerationCount(-1)==0)
	{
		score++;
	}
	if(score==10)
	{
		cout<<"Passed!"<<endl;
	}
	else
	{
		cout<<"Failed"<<endl;
	}

	cout<<endl;
	cout<<"Testing GenerationGap..."<<endl;
	score=0;
	if(t.GenerationGap("Ayesha", "Neha")==6 && t.GenerationGap("Ayesha", "Neha")==t.GenerationGap("Neha", "Ayesha"))
	{
		score++;
	}
	if(t.GenerationGap("Zoya", "Khalid")==3)
	{
		score++;
	}
	if(t.GenerationGap("Ibrahim", "Tariq")==2)
	{
		score++;
	}
	if(t.GenerationGap("Beenish", "Anees")==0)
	{
		score++;
	}
	if(t.GenerationGap("Talha", "Emad")==2)
	{
		score++;
	}
	if(t.GenerationGap("Sehar", "Mahnoor")==3)
	{
		score++;
	}
	if(t.GenerationGap("Hamza", "Areej")==1)
	{
		score++;
	}
	if (score==7)
	{
		cout<<"Passed!"<<endl;
	}
	else
	{
		cout<<"Failed!"<<endl;
	}

	// tree traversal
    cout << "---- level order tree traversal -------- " << endl;
    t.level_traversal();
}
