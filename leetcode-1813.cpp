class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int count1 = 0, count2 = 0;
        int i = 0;
        vector<string> sen1, sen2;
        while(i < sentence1.length()){
            int j = i;
            while(i < sentence1.length() && sentence1[i] != ' '){
                i++;
            }
            sen1.push_back(sentence1.substr(j, i-j));
            count1++;
            i++;
        }
        i = 0;
        while(i < sentence2.length()){
            int j = i;
            while(i < sentence2.length() && sentence2[i] != ' '){
                i++;
            }
            sen2.push_back(sentence2.substr(j, i-j));
            count2++;
            i++;
        }
        if(count2 > count1){
            vector<string> temp;
            temp = sen1;
            sen1 = sen2;
            sen2 = temp;
            int count = count1;
            count1 = count2;
            count2 = count;
        }
        int index1 = 0, index2 = 0;
        bool isInsert = false;
        while(index1 < count1 && index2 < count2){
            if(sen1[index1] == sen2[index2]){
                index1++;
                index2++;
            }
            else{
                if(!isInsert){
                    index1 += (count1-count2);
                    isInsert = true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
