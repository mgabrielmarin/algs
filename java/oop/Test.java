class Test {
    public static int raiseSalary(int salary, int percent) {
	int raise = salary * (percent/100);
	System.out.println("percent/100: " + (double)percent/100);
	System.out.println("salary * percent/100: " + (int)((double)salary * (double)percent/100));
	salary += raise;
	return salary;
    }
		
    public static void main(String[] args) {
	int salary = 999;
	raiseSalary(salary, 10);
	salary = raiseSalary(salary, 10);
	System.out.println("Salary: " + salary);
    }
}
