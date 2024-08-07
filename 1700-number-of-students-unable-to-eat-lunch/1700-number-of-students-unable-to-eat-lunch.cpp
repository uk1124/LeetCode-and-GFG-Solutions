class Solution {
public:
    /*APPROACH: Using Queue.
    Initialize a rotations variable with 0 and a counter variable (i) with 0.
    Traverse the queue until it is empty and rotations is less than size of queue.
    If front value of queue == sandwiches at i index
    Pop it from queue, increase the counter variable i and set rotations = 0.
    Else take it from queue, push it back and pop it from front. Increase the number of rotations.
    Return size of queue. */
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size();
        queue<int> student_choice;
        for(int i = 0; i < size; i++) {
            student_choice.push(students[i]);
        }
        int rotations = 0, i = 0;
        while(student_choice.size() and rotations < student_choice.size()) {
            if(student_choice.front() == sandwiches[i]) {
                student_choice.pop();
                i++;
                rotations = 0;
            } 
            else {
                int choice = student_choice.front();
                student_choice.pop();
                student_choice.push(choice);
                rotations++;
            }
        }
        return student_choice.size();
    }
};